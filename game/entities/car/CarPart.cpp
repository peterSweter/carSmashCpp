//
// Created by peter on 4/14/18.
//

#include <iostream>
#include "CarPart.h"

CarPart::CarPart(b2Body * body, CarPartPrototype *carPartPrototype) :  body_(body) , carPartPrototype_(carPartPrototype) {
    std::cout << "[CarPart] constructor" << std::endl;
    fixture_ = body_->CreateFixture(carPartPrototype->getFixtureDef());

    std::cout << "[CarPart] created fixture" << std::endl;


    fixture_->SetUserData(this);

    this->setDurability(carPartPrototype->durability_);
    color_ =  carPartPrototype->color_;

}

std::shared_ptr<Json> CarPart::getJsonData() {


    return std::make_shared<Json>(Json::parse(*carPartPrototype_->getJsonDisplayData()));

}

CarPart::~CarPart() {
    std::cout << "[CarPart] Deconstruction." << std::endl;
}
