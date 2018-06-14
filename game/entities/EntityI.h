//
// Created by peter on 3/31/18.
//

#ifndef CARSMASHCPP_ENTITYI_H
#define CARSMASHCPP_ENTITYI_H


class InteractiveEntityPartA;

class EntityI {

private:

    double healthPoints_;
    int myMask_;
    int maskCollideWith_;

public:

    virtual void update() = 0;
    virtual void dealDamage(InteractiveEntityPartA *entity, double dmg) = 0;

    virtual bool isAlive();
    virtual double getDamageFactor();

    //returns actual damage  taken

    virtual double takeDamage(double dmg);
    virtual void setHealth(double val);
    virtual void setMyMask(int);
    virtual void setMaskCollideWith(int);

    virtual double getHealth();
    virtual int getMask();
    virtual int getMaskCollitdeWith();
};


#endif //CARSMASHCPP_ENTITYI_H
