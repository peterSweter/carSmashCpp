//
// Created by peter on 4/14/18.
//

#include "Car.h"

Car::Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager * box2dManager) : box2dManager_(box2dManager) {

    // creating car from carProtorype

    // creating bodies:

    for(auto carBodyPrototype : carPrototype->carBodyPrototypes_){

        std::string bodyName = carBodyPrototype.first;

        b2Body * body  = box2dManager_->createBody(&carBodyPrototype.second.bodyDef_);

        bodies_.emplace(bodyName, body);

        //creating carparts

        for(auto carPart : carBodyPrototype.second.carParts_){
            carParts_.emplace(carPart.first, CarPart(body, &carPart.second));

        }



    }

    //joint boides
    //TODO joint bodies



}
