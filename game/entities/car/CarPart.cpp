//
// Created by peter on 4/14/18.
//

#include "CarPart.h"

CarPart::CarPart(b2Body * body, CarPartPrototype *carPartPrototype) :  body_(body) {
    fixture_ = body_->CreateFixture(&carPartPrototype->fixtureDef_);
    durability_ = carPartPrototype->durability_;
    color_ =  carPartPrototype->color_;
}
