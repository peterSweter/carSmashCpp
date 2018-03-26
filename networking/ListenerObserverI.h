//
// Created by peter on 3/26/18.
//

#ifndef CARSMASHCPP_LISTENEROBSERVERI_H
#define CARSMASHCPP_LISTENEROBSERVERI_H


#include "SessionI.h"

class ListenerObserverI {
public:
    virtual void pushNewSession(std::shared_ptr<SessionI> sessionI) = 0;
};


#endif //CARSMASHCPP_LISTENEROBSERVERI_H
