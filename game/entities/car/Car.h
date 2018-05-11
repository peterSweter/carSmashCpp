//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CAR_H
#define CARSMASHCPP_CAR_H


#include <map>
#include <Box2D/Box2D.h>
#include "CarPart.h"
#include "CarPrototype.h"
#include "../../box2D/Box2dManager.h"

#include "../../dataCollector/DataCollectableOnceI.h"
#include "../../player/PlayerI.h"
#include "../../input/KeyboardManager.h"


class Car : public DataCollectableOnceI {

    Box2dManager * box2dManager_;
    PlayerI * player_;
    KeyboardManager * keyboardManager_ = nullptr;


public:

    std::map<std::string,b2Body*> bodies_;
    std::map<std::string, CarPart> carParts_;

    Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager * box2dManager);
    void setPlayer(PlayerI * player);
    void setKeyboardManager(KeyboardManager * keyboardManager);
    void update();
    b2Vec2 getPosition();

    //TODO checking if data was fetched already from this object
    std::string getJsonData();


};


#endif //CARSMASHCPP_CAR_H
