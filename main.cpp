#include <iostream>
#include "networking/WebSocketServerAsync.h"

int main() {
    std::cout << "Test serwera: " << std::endl;

    WebSocketServerAsync webSocketServerAsync;
    std::thread v([&](){webSocketServerAsync.run();});

    v.join();


    return 0;
}