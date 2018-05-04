//
// Created by peter on 5/4/18.
//

#include <string>
#include "DataCollectableOnceI.h"

std::string DataCollectableOnceI::getJsonData(Player *playerPtr, bool updateCounter) {

    if(lastUpdatePlayerPtr_ == playerPtr && updateCounter_ == updateCounter ){
        return "";
    }

    setGuards(playerPtr, updateCounter);

    return getJsonData();
}

void DataCollectableOnceI::setGuards(Player *playerPtr, bool updateCounter) {
    this->lastUpdatePlayerPtr_ = playerPtr;
    this->updateCounter_ = updateCounter;
}
