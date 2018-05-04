//
// Created by peter on 5/3/18.
//

#ifndef CARSMASHCPP_DATACOLLECTABLEI_H
#define CARSMASHCPP_DATACOLLECTABLEI_H


#include <string>

class DataCollectableI {

public:
    virtual std::string getJsonData() = 0;

};


#endif //CARSMASHCPP_DATACOLLECTABLEI_H
