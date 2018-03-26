//
// Created by peter on 2/10/18.
//

#include "WebSocketServerAsync.h"

WebSocketServerAsync::WebSocketServerAsync() {
    this->address_ = boost::asio::ip::make_address("0.0.0.0");
    this->port_ = static_cast<unsigned short>(8080);
    this->threads_ = std::max<int>(1, 1);

}

void WebSocketServerAsync::run() {
// The io_context is required for all I/O
    boost::asio::io_context ioc{threads_};

// Create and launch a listening port_
    listener_ = std::make_shared<Listener>(ioc, tcp::endpoint{address_, port_});
    listener_->run();

// Run the I/O service on the requested number of threads_
    threadVec_.reserve(threads_);
    for (auto i = threads_ - 1; i > 0; --i)
        threadVec_.emplace_back(
                [&ioc] {
                    ioc.run();
                });


    std::cout << "[Server] Spawned successfully." << std::endl;
    ioc.run();
}

std::shared_ptr<ListenerI> WebSocketServerAsync::getListener() {
    return listener_;
}

void WebSocketServerAsync::registerObserver(ListenerObserverI *listenerObserverI) {
    //assert(listener_!= nullptr);
    listener_->registerObserver(listenerObserverI);
}
