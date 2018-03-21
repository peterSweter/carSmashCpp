//
// Created by peter on 3/19/18.
//

#ifndef CARSMASHCPP_LISTENER_H
#define CARSMASHCPP_LISTENER_H

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
#include "Session.h"
#include "ListenerI.h"

using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>
namespace websocket = boost::beast::websocket;  // from <boost/beast/websocket.hpp>

//------------------------------------------------------------------------------



// Accepts incoming connections and launches the sessions
class Listener : public std::enable_shared_from_this<Listener> , ListenerI{
    tcp::acceptor acceptor_;
    tcp::socket socket_;
    std::mutex mutex_;
    std::queue<std::shared_ptr<Session>> sessionQ_;

public:



    Listener(boost::asio::io_context &ioc, tcp::endpoint endpoint);

    // Start accepting incoming connections
    void run();
    void do_accept();

    void on_accept(boost::system::error_code ec);

private:
    std::mutex& getMutex() override;

    std::queue<std::shared_ptr<Session>> &getSessionQueue() override;
};

#endif //CARSMASHCPP_LISTENER_H
