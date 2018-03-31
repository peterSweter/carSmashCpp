//
// Created by peter on 2/10/18.
//

#include <memory>
#include "WebSocketServerAsync.h"

WebSocketServerAsync::WebSocketServerAsync() : threads_(4), ioc_{threads_} {
    this->address_ = boost::asio::ip::make_address("0.0.0.0");
    this->port_ = static_cast<unsigned short>(8080);
    listener_ = std::make_shared<Listener>(ioc_, tcp::endpoint{address_, port_});
}

void WebSocketServerAsync::run() {


    listener_->run();

// Run the I/O service on the requested number of threads_
    threadVec_.reserve(threads_);
    for (auto i = threads_ - 1; i >= 0; --i)
        threadVec_.emplace_back(
                [this] {
                    ioc_.run();
                });


    std::cout << "[Server] Spawned successfully." << std::endl;
    //ioc_.run();
}

std::shared_ptr<ListenerI> WebSocketServerAsync::getListener() {
    return listener_;
}

void WebSocketServerAsync::registerObserver(ListenerObserverI *listenerObserverI) {
    assert(listener_!= nullptr);
    listener_->registerObserver(listenerObserverI);
}
