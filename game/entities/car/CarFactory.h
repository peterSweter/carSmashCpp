//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARFACTORY_H
#define CARSMASHCPP_CARFACTORY_H


#include "../../box2D/Box2dManager.h"
#include "Car.h"
#include "CarModels.h"

class Car;
class CarFactory {
private:

    Box2dManager * box2dManager_;
    CarModels carModels_;
public:

    CarFactory(Box2dManager * box2dManager);
    std::shared_ptr<Car>create(std::string carModelID);


    ~CarFactory();

};


#endif //CARSMASHCPP_CARFACTORY_H
