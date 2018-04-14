//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARFACTORY_H
#define CARSMASHCPP_CARFACTORY_H


#include "../../box2D/Box2dManager.h"
#include "Car.h"

class CarFactory {
private:

    Box2dManager * box2dManager_;
public:

    CarFactory(Box2dManager * box2dManager);
    std::shared_ptr<Car>create(std::string carModelID);

};


#endif //CARSMASHCPP_CARFACTORY_H
