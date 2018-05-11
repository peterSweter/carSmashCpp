//
// Created by peter on 5/4/18.
//

#include <string>
#include "DataCollectableOnceI.h"
#include "DataCollector.h"

std::string DataCollectableOnceI::getJsonData(DataCollector *dataCollectorPtr, bool updateCounter) {

    if(lastUpdatePlayerPtr_ == dataCollectorPtr && updateCounter_ == updateCounter ){
        return "";
    }

    setGuards(dataCollectorPtr, updateCounter);

    return getJsonData();
}

void DataCollectableOnceI::setGuards(DataCollector *dataCollectorPtr, bool updateCounter) {
    this->lastUpdatePlayerPtr_ = dataCollectorPtr;
    this->updateCounter_ = updateCounter;
}
