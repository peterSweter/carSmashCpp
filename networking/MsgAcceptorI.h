//
// Created by peter on 5/11/18.
//

#ifndef CARSMASHCPP_MSGACCEPTORI_H
#define CARSMASHCPP_MSGACCEPTORI_H


#include "SessionI.h"

class MsgAcceptorI {
public:
    virtual void handleMessage(std::shared_ptr<Json> message) = 0;
};


#endif //CARSMASHCPP_MSGACCEPTORI_H
