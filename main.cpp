#include <iostream>
#include "networking/WebSocketServerAsync.h"

int main() {
    std::cout << "Test serwera: " << std::endl;

    WebSocketServerAsync webSocketServerAsync;
    webSocketServerAsync.run();

    return 0;
}