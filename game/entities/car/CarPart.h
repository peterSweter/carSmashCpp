//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARPART_H
#define CARSMASHCPP_CARPART_H


#include <Box2D/Dynamics/b2Body.h>
#include "CarPartPrototype.h"

class CarPart {
public:
    b2Body * body_;
    b2Fixture * fixture_;
    double durability_;
    std::string color_;


    CarPart(b2Body * body , CarPartPrototype * carPartPrototype);
};


#endif //CARSMASHCPP_CARPART_H
