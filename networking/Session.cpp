//
// Created by peter on 3/19/18.
//

#include "Session.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Report a failure
void
fail(boost::system::error_code ec, char const *what) {
    std::cerr << what << ": " << ec.message() << "\n";
}

// Echoes back all received WebSocket messages

// Take ownership of the socket
Session::Session(tcp::socket socket) : ws_(std::move(socket)), strand_(ws_.get_executor()) {
}

// Start the asynchronous operation
void Session::run() {

    json test;
    test["koles"] = "zbyszek";
    std::cout << test.dump();

    // Accept the websocket handshake
    ws_.async_accept(
            boost::asio::bind_executor(
                    strand_,
                    std::bind(
                            &Session::on_accept,
                            shared_from_this(),
                            std::placeholders::_1)));
}

void Session::on_accept(boost::system::error_code ec) {
    if (ec)
        return fail(ec, "accept");

    // Read a message
    do_read();

}

void Session::do_read() {
    // Read a message into our buffer

    ws_.async_read(
            buffer_,
            boost::asio::bind_executor(
                    strand_,
                    std::bind(
                            &Session::on_read,
                            shared_from_this(),
                            std::placeholders::_1,
                            std::placeholders::_2)));
}

void Session::on_read(boost::system::error_code ec, std::size_t bytes_transferred) {

    boost::ignore_unused(bytes_transferred);

    // This indicates that the Session was closed
    if (ec == websocket::error::closed)
        return;

    if (ec)
        fail(ec, "read");

    // Echo the message // super usefull
    //std::cout << boost::beast::buffers(buffer_.data()) << "\n";
    //  boost::beast::ostream(buffer_) << "dodatkowy msg\n";

    std::ostringstream os;
    os << boost::beast::buffers(buffer_.data());
    std::string strMsgJson = os.str();


    ws_.text(ws_.got_text());

    mutexReceived_.lock();
    receivedMessagesQ_.emplace(strMsgJson);
    mutexReceived_.unlock();

    // Clear the buffer
    buffer_.consume(buffer_.size());

    // Do another read
    do_read();

}

void Session::on_write(boost::system::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec)
        return fail(ec, "write");

    outBuffer_.consume(outBuffer_.size());

    mutexToSend_.lock();
    if(toSendMessagesQ_.empty()){

        isWriting_ = false;
    }else{
        do_write();
    }
    mutexToSend_.unlock();

}

void Session::do_write() {



    mutexToSend_.lock();
    std::string message = toSendMessagesQ_.front().dump();
    toSendMessagesQ_.pop();
    mutexToSend_.unlock();

    boost::beast::ostream(outBuffer_) << message;
    ws_.async_write(
            outBuffer_.data(),
            boost::asio::bind_executor(
                    strand_,
                    std::bind(
                            &Session::on_write,
                            shared_from_this(),
                            std::placeholders::_1,
                            std::placeholders::_2)));

}

void Session::sendJSON(Json msg) {

    mutexToSend_.lock();
    toSendMessagesQ_.emplace(msg);
    mutexToSend_.unlock();

    if(!isWriting_){
        isWriting_ = true;
        do_write();
    }

}

std::queue<Json> &Session::getMessages() {
    return receivedMessagesQ_;
}

std::mutex &Session::getMutex() {
    return mutexReceived_;
}

bool Session::hasMessages() {
    return receivedMessagesQ_.empty();
}
