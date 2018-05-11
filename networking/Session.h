//
// Created by peter on 3/19/18.
//

#ifndef CARSMASHCPP_SESSION_H
#define CARSMASHCPP_SESSION_H


#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/bind_executor.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <bits/unordered_set.h>
#include <unordered_set>
#include <mutex>
#include "SessionI.h"
#include "../utils/ThreadSafeQueue.h"
#include <boost/optional.hpp>


using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>
namespace websocket = boost::beast::websocket;  // from <boost/beast/websocket.hpp>


//------------------------------------------------------------------------------

void fail(boost::system::error_code ec, char const *what);


class Session : public std::enable_shared_from_this<Session>, public SessionI {
    websocket::stream<tcp::socket> ws_;
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::beast::multi_buffer buffer_;
    boost::beast::multi_buffer outBuffer_;


    //TODO change to lockfree queues




    //it is staying there
    ThreadSafeQueue<std::shared_ptr<Json>> toSendMessagesQ_;


private:


    //should i push it to the player queue as an observer ?
    ThreadSafeQueue<std::shared_ptr<Json>> receivedMessagesQ_;
    bool isWriting_;


public:
    // Take ownership of the socket
    explicit Session(tcp::socket socket);


    // Start the asynchronous operation
    void run();

    void on_accept(boost::system::error_code ec);

    void do_read();
    void on_read(boost::system::error_code ec, std::size_t bytes_transferred) ;

    void on_write(boost::system::error_code ec, std::size_t bytes_transferred) ;

    void do_write();

    void sendJSON(Json msg) override;

    void sendJSON(std::shared_ptr<Json> msg) override;

    ThreadSafeQueue<std::shared_ptr<Json>> * getMessages() override;



    bool hasMessages() override;
};


#endif //CARSMASHCPP_SESSION_H
