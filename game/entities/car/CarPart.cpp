//
// Created by peter on 4/14/18.
//

#include "CarPart.h"

CarPart::CarPart(b2Body * body, CarPartPrototype *carPartPrototype) :  body_(body) , carPartPrototype_(carPartPrototype) {

    fixture_ = body_->CreateFixture(&carPartPrototype->fixtureDef_);
    fixture_->SetUserData(this);
    durability_ = carPartPrototype->durability_;
    color_ =  carPartPrototype->color_;
}

std::string CarPart::getJsonData() {

    return *carPartPrototype_->getJsonDisplayData();
}
