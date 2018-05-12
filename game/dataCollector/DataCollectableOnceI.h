//
// Created by peter on 5/4/18.
//

#ifndef CARSMASHCPP_DATACOLLECTABLEONCE_H
#define CARSMASHCPP_DATACOLLECTABLEONCE_H


#include "DataCollectableI.h"
#include "DataCollector.h"
#include "../../networking/SessionI.h"

class Player;

class DataCollectableOnceI : public DataCollectableI {
private:
    bool updateCounter_ = false;
    DataCollector *lastUpdatePlayerPtr_ = nullptr;

    virtual std::shared_ptr<Json> getJsonData() = 0;

    void setGuards(DataCollector *dataCollectorPtr, bool updateCounter);

public:
    std::shared_ptr<Json> getJsonData(DataCollector *dataCollectorPtr, bool updateCounter);


};


#endif //CARSMASHCPP_DATACOLLECTABLEONCE_H
