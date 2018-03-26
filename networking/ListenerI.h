//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_LISTERNERI_H
#define CARSMASHCPP_LISTERNERI_H


#include <mutex>
#include <memory>
#include <boost/lockfree/queue.hpp>
#include "Session.h"
#include "ListenerObserverI.h"

class ListenerI {
public:
    virtual void registerObserver(ListenerObserverI *listenerObserverI) = 0;
};


#endif //CARSMASHCPP_LISTERNERI_H
