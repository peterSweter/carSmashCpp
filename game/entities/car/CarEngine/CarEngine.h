//
// Created by peter on 5/30/18.
//

#ifndef CARSMASHCPP_CARENGINE_H
#define CARSMASHCPP_CARENGINE_H


#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/Joints/b2RevoluteJoint.h>
#include "../../../input/KeyboardManager.h"
#include "../../../../utils/Utilities.h"

class CarEngine {

private:

    KeyboardManager * keyboardManager;
    b2Body * frontTires[2];
    b2Body * tires[4];

    b2RevoluteJoint * frontJoints_[2];

    void kilLateralVelocity();
    b2Vec2 getLateralVelocity(b2Body * body);
    b2Vec2 getForwardVelocity(b2Body * body);
    void updateFriction(b2Body * body);
    void updateDrive(b2Body *body);
    void updateSteering();

    float maxForwardSpeed_  = 10.0;
    float maxBackWardSpeed_ = -2.5;
    float maxDriveForce_ = 5.0;

    float lockAngle = 40.0 * DEGTORAD;
    float turnSpeedPerSecond = 320.0 * DEGTORAD;
    float turnPerTimeStep = turnSpeedPerSecond/60.0;


public:

    void update();

    void setFrontTires(b2Body *tire0, b2Body *tire1);
    void setTires(b2Body *tire0, b2Body *tire1,b2Body *tire3, b2Body *tire4);
    void setFrontJoints(std::vector<b2RevoluteJoint *> &);
    void setKeyboardManager(KeyboardManager * keyboardManager);

};


#endif //CARSMASHCPP_CARENGINE_H
