//
// Created by peter on 6/13/18.
//

#include "InteractiveEntityPartA.h"

bool InteractiveEntityPartA::colideWidth(InteractiveEntityPartA *iEntity) {

    if(iEntity->entity_ == nullptr || this->entity_ == nullptr){
        return false;
    }

    return (bool) iEntity->entity_->getMask() & this->entity_->getMaskCollitdeWith();

}

void InteractiveEntityPartA::setEntity(EntityI *entity) {
    this->entity_ = entity;

}

void InteractiveEntityPartA::dealDamage(InteractiveEntityPartA *iEntity, double dmg) {
    if(this->entity_ == nullptr){
        return;
    }

    this->entity_->dealDamage(iEntity, dmg);
}

double InteractiveEntityPartA::takeDamage(double dmg) {
    return this->entity_->takeDamage(this->durability_ * dmg);
}

void InteractiveEntityPartA::setDurability(double val) {
    this->durability_ = durability_;
}
