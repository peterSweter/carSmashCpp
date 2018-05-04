//
// Created by peter on 5/4/18.
//

#ifndef CARSMASHCPP_DATACOLLECTABLEONCE_H
#define CARSMASHCPP_DATACOLLECTABLEONCE_H


#include "DataCollectableI.h"

class Player;

class DataCollectableOnceI : public DataCollectableI {
private:
    bool updateCounter_ = false;
    Player *lastUpdatePlayerPtr_ = nullptr;

    virtual std::string getJsonData() = 0;

    void setGuards(Player *playerPtr, bool updateCounter);

public:
    std::string getJsonData(Player *playerPtr, bool updateCounter);


};


#endif //CARSMASHCPP_DATACOLLECTABLEONCE_H
