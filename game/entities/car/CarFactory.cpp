//
// Created by peter on 4/14/18.
//

#include <iostream>
#include "CarFactory.h"

CarFactory::CarFactory(Box2dManager *box2dManager) :box2dManager_(box2dManager) {
    std::cout << "[CarFactory] Creating." << std::endl<<std::flush;
}

std::shared_ptr<Car> CarFactory::create(std::string carModelID) {

    // creating box2d body and inserting it into the world

    std::cout << "[Car factory] Creating carmodel" << std::endl;


    auto carPrototype  = carModels_.getModel(carModelID);
    std::cout << "[Car factory] Have ptr to car model." << std::endl;

    auto carPtr = std::make_shared<Car>(carPrototype, box2dManager_);
    return carPtr;
}

CarFactory::~CarFactory() {
    std::cout << "[CarFactory] Deconstructor." << std::endl;
}
