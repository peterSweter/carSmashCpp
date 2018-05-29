//
// Created by peter on 5/4/18.
//

#ifndef CARSMASHCPP_DATACOLLECTABLEONCE_H
#define CARSMASHCPP_DATACOLLECTABLEONCE_H


#include "DataCollectableI.h"





class DataCollectableOnceI : public DataCollectableI {
private:
    bool updateCounter_ = false;
    void *lastUpdatePlayerPtr_ = nullptr;

    virtual std::shared_ptr<Json> getJsonData() = 0;

    void setGuards(void *dataCollectorPtr, bool updateCounter);

public:
    std::shared_ptr<Json> getJsonData(void *dataCollectorPtr, bool updateCounter);


};


#endif //CARSMASHCPP_DATACOLLECTABLEONCE_H
