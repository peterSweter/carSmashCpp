//
// Created by peter on 2/10/18.
//

#ifndef CARSMASHCPP_WEBSOCKETSERVERASYNC_H
#define CARSMASHCPP_WEBSOCKETSERVERASYNC_H


#include <vector>
#include "Session.h"
#include "Listener.h"


class WebSocketServerAsync : ListenerI {

    boost::asio::ip::address address_;
    unsigned short port_;
    int threads_;
    std::shared_ptr<Listener> listener_;
    std::vector<std::thread> threadVec_;
    boost::asio::io_context ioc_;


public:

    WebSocketServerAsync();
    void run();
    std::shared_ptr<ListenerI> getListener();


    void registerObserver(ListenerObserverI *listenerObserverI) override;

};


#endif //CARSMASHCPP_WEBSOCKETSERVERASYNC_H
