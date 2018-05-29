//
// Created by peter on 5/4/18.
//

#include <string>
#include "DataCollectableOnceI.h"
#include "DataCollector.h"

std::shared_ptr<Json> DataCollectableOnceI::getJsonData(void *dataCollectorPtr, bool updateCounter) {

    if(lastUpdatePlayerPtr_ == dataCollectorPtr && updateCounter_ == updateCounter ){
        return nullptr;
    }

    setGuards(dataCollectorPtr, updateCounter);

    return getJsonData();
}

void DataCollectableOnceI::setGuards(void *dataCollectorPtr, bool updateCounter) {
    this->lastUpdatePlayerPtr_ = dataCollectorPtr;
    this->updateCounter_ = updateCounter;
}
