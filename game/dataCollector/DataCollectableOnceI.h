//
// Created by peter on 5/4/18.
//

#ifndef CARSMASHCPP_DATACOLLECTABLEONCE_H
#define CARSMASHCPP_DATACOLLECTABLEONCE_H


#include "DataCollectableI.h"
#include "DataCollector.h"

class Player;

class DataCollectableOnceI : public DataCollectableI {
private:
    bool updateCounter_ = false;
    DataCollector *lastUpdatePlayerPtr_ = nullptr;

    virtual std::string getJsonData() = 0;

    void setGuards(DataCollector *dataCollectorPtr, bool updateCounter);

public:
    std::string getJsonData(DataCollector *dataCollectorPtr, bool updateCounter);


};


#endif //CARSMASHCPP_DATACOLLECTABLEONCE_H
