//
// Created by peter on 6/13/18.
//

#include <iostream>
#include "InteractiveEntityPartA.h"

bool InteractiveEntityPartA::colideWidth(InteractiveEntityPartA *iEntity) {
    return true;



    if(iEntity->entity_ == nullptr || this->entity_ == nullptr){
        return false;
    }

    return (bool) (iEntity->entity_->getMask() & this->entity_->getMaskCollitdeWith());

}

void InteractiveEntityPartA::setEntity(EntityI *entity) {
    std::cout <<  "entity has been seet" << std::endl;
    this->entity_ = entity;

}

void InteractiveEntityPartA::dealDamage(InteractiveEntityPartA *iEntity, double dmg) {
    std::cout << "Dealing damage " << std::endl;
    if(this->entity_ == nullptr){
        return;
    }

    this->entity_->dealDamage(iEntity, dmg);
}

double InteractiveEntityPartA::takeDamage(double dmg) {
    std::cerr << "durabiluity: " << this->durability_ << std::endl;
    return this->entity_->takeDamage((1.0-this->durability_) * dmg);
}

void InteractiveEntityPartA::setDurability(double val) {
    this->durability_ = val;
}
