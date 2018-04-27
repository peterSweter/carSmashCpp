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

class Car {

    Box2dManager * box2dManager_;

public:

    std::map<std::string,b2Body*> bodies_;
    std::map<std::string, CarPart> carParts_;

    Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager * box2dManager);




};


#endif //CARSMASHCPP_CAR_H
