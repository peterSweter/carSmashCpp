//
// Created by peter on 3/19/18.
//

#include "Session.h"

// Echoes back all received WebSocket messages

// Take ownership of the socket
explicit session::session(tcp::socket socket) : ws_(std::move(socket)), strand_(ws_.get_executor()) {
}

// Start the asynchronous operation
void session::run() {
    // Accept the websocket handshake
    ws_.async_accept(
            boost::asio::bind_executor(
                    strand_,
                    std::bind(
                            &session::on_accept,
                            shared_from_this(),
                            std::placeholders::_1)));
}

void session::on_accept(boost::system::error_code ec) {
    if (ec)
        return fail(ec, "accept");

    // Read a message
    do_read();
}

void session::do_read() {
    // Read a message into our buffer
    ws_.async_read(
            buffer_,
            boost::asio::bind_executor(
                    strand_,
                    std::bind(
                            &session::on_read,
                            shared_from_this(),
                            std::placeholders::_1,
                            std::placeholders::_2)));
}

void session::on_read(boost::system::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    // This indicates that the session was closed
    if (ec == websocket::error::closed)
        return;

    if (ec)
        fail(ec, "read");

    // Echo the message
    buffer_.data();
    ws_.text(ws_.got_text());
    ws_.async_write(
            buffer_.data(),
            boost::asio::bind_executor(
                    strand_,
                    std::bind(
                            &session::on_write,
                            shared_from_this(),
                            std::placeholders::_1,
                            std::placeholders::_2)));
}

void session::on_write(boost::system::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec)
        return fail(ec, "write");

    // Clear the buffer
    buffer_.consume(buffer_.size());

    // Do another read
    do_read();
}
