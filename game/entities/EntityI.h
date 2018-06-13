//
// Created by peter on 3/31/18.
//

#ifndef CARSMASHCPP_ENTITYI_H
#define CARSMASHCPP_ENTITYI_H


class EntityI {
private:
    double healtPoints;

public:

    virtual void update() = 0;
    virtual bool isAlive() = 0;
    virtual double getDamageFactor() = 0;
    virtual double getDamage(double dmg) = 0;
};


#endif //CARSMASHCPP_ENTITYI_H
