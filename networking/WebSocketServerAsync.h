//
// Created by peter on 2/10/18.
//

#ifndef CARSMASHCPP_WEBSOCKETSERVERASYNC_H
#define CARSMASHCPP_WEBSOCKETSERVERASYNC_H


#include <vector>
#include "Session.h"
#include "Listener.h"


class WebSocketServerAsync {

    boost::asio::ip::address address;
    unsigned short port;
    int threads;


public:

    WebSocketServerAsync();
    void run();

};


#endif //CARSMASHCPP_WEBSOCKETSERVERASYNC_H
