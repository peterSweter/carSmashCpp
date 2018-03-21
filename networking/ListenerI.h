//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_LISTERNERI_H
#define CARSMASHCPP_LISTERNERI_H


#include <mutex>
#include <memory>
#include "Session.h"

class ListenerI {
    virtual std::mutex &getMutex() = 0;
    virtual std::queue<std::shared_ptr<Session>> & getSessionQueue() = 0;
};


#endif //CARSMASHCPP_LISTERNERI_H
