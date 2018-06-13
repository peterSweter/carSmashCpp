//
// Created by peter on 6/13/18.
//

#ifndef CARSMASHCPP_INTERACTIVEENTITYA_H
#define CARSMASHCPP_INTERACTIVEENTITYA_H


#include "../../entities/EntityI.h"

class InteractiveEntityA {
private:
    EntityI * entity;
    double durability;
    bool staticEntity;

public:

    virtual void getDamage(double) = 0;
    virtual double getDamageFactor() = 0;

};


#endif //CARSMASHCPP_INTERACTIVEENTITYA_H
