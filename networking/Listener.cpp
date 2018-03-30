//
// Created by peter on 3/19/18.
//

#include "Listener.h"
#include "../Game.h"


Listener::Listener(boost::asio::io_context &ioc, tcp::endpoint endpoint) : acceptor_(ioc), socket_(ioc) {

    boost::system::error_code ec;

    // Open the acceptor
    acceptor_.open(endpoint.protocol(), ec);
    if (ec) {
        fail(ec, "open");
        return;
    }

    // Bind to the server address_
    acceptor_.bind(endpoint, ec);
    if (ec) {
        fail(ec, "bind");
        return;
    }

    // Start listening for connections
    acceptor_.listen(
            boost::asio::socket_base::max_listen_connections, ec);
    if (ec) {
        fail(ec, "listen");
        return;
    }
}

// Start accepting incoming connections
void Listener::run() {
    if (!acceptor_.is_open())
        return;
    do_accept();

    std::cout << "listener is running" << std::endl;
}

void Listener::do_accept() {
    acceptor_.async_accept(
            socket_,
            std::bind(
                    &Listener::on_accept,
                    shared_from_this(),
                    std::placeholders::_1));
}

void Listener::on_accept(boost::system::error_code ec) {
    if (ec) {
        fail(ec, "accept");
    } else {
        // Create the Session and run it

        auto newClient = std::make_shared<Session>(std::move(socket_));
        assert(listenerObserverI_ != nullptr);
        listenerObserverI_->pushNewSession(newClient);

        newClient->run();
    }

    // Accept another connection
    do_accept();

}

void Listener::registerObserver(ListenerObserverI *listenerObserverI) {
    std::cout << "[Listener] Observer registered" << std::endl;
    listenerObserverI_ = listenerObserverI;
}



