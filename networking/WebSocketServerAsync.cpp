//
// Created by peter on 2/10/18.
//

#include "WebSocketServerAsync.h"

WebSocketServerAsync::WebSocketServerAsync() {
    this->address = boost::asio::ip::make_address("0.0.0.0");
    this->port = static_cast<unsigned short>(8080);
    this->threads = std::max<int>(1, 4);

}

void WebSocketServerAsync::run() {
// The io_context is required for all I/O
    boost::asio::io_context ioc{threads};

// Create and launch a listening port
    std::make_shared<Listener>(ioc, tcp::endpoint{address, port})->run();

// Run the I/O service on the requested number of threads
    std::vector<std::thread> v;
    v.reserve(threads - 1);
    for (auto i = threads - 1; i > 0; --i)
        v.emplace_back(
                [&ioc] {
                    ioc.run();
                });
    ioc.run();
}
