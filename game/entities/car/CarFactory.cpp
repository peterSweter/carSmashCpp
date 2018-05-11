//
// Created by peter on 4/14/18.
//

#include <iostream>
#include "CarFactory.h"

CarFactory::CarFactory(Box2dManager *box2dManager) :box2dManager_(box2dManager) {
    std::cout << "Car Factory Creating." << std::endl<<std::flush;
}

std::shared_ptr<Car> CarFactory::create(std::string carModelID) {

    // creating box2d body and inserting it into the world



    auto carPrototype  = carModels_.getModel(carModelID);
    auto carPtr = std::make_shared<Car>(carPrototype, box2dManager_);
    return carPtr;
}
