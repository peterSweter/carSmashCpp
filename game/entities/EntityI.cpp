//
// Created by peter on 3/31/18.
//

#include "EntityI.h"

void EntityI::setHealth(double val) {
    healthPoints_ = val;
}

void EntityI::setMyMask(int mask) {
    myMask_ = mask;
}

void EntityI::setMaskCollideWith(int mask) {
 maskCollideWith_ = mask;
}

bool EntityI::isAlive() {
    return healthPoints_ > 0;
}

double EntityI::getHealth() {
    return healthPoints_;
}

int EntityI::getMask() {
    return myMask_;
}

int EntityI::getMaskCollitdeWith() {
    return maskCollideWith_;
}

double EntityI::takeDamage(double dmg) {
    return healthPoints_ -= dmg;
}

double EntityI::getDamageFactor() {

    //TODO damage factor will be taken from car upgrades
    return 1.0;
}
