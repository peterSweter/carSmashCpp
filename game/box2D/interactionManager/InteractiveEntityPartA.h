//
// Created by peter on 6/13/18.
//

#ifndef CARSMASHCPP_INTERACTIVEENTITYA_H
#define CARSMASHCPP_INTERACTIVEENTITYA_H


#include "../../entities/EntityI.h"

class InteractiveEntityPartA {
private:
    EntityI * entity_ = nullptr;
    double durability_;

public:

    virtual double takeDamage(double);
    virtual void dealDamage(InteractiveEntityPartA * iEntity, double dmg);
    virtual bool colideWidth(InteractiveEntityPartA * iEntity);

    virtual void setEntity(EntityI * entity);
    virtual void setDurability(double);

};


#endif //CARSMASHCPP_INTERACTIVEENTITYA_H
