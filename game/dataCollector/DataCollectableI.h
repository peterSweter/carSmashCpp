//
// Created by peter on 5/3/18.
//

#ifndef CARSMASHCPP_DATACOLLECTABLEI_H
#define CARSMASHCPP_DATACOLLECTABLEI_H


#include <string>
#include "../../networking/SessionI.h"

class DataCollectableI {

public:
    virtual std::shared_ptr<Json> getJsonData() = 0;

};


#endif //CARSMASHCPP_DATACOLLECTABLEI_H
