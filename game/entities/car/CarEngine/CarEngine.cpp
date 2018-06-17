//
// Created by peter on 5/30/18.
//

#include <iostream>
#include "CarEngine.h"



void CarEngine::setFrontTires(b2Body *tire0, b2Body *tire1) {

    frontTires[0] = tire0;
    frontTires[1] = tire1;

}

void CarEngine::setKeyboardManager(KeyboardManager *keyboardManager) {
    this->keyboardManager = keyboardManager;
}

void CarEngine::update() {



    for(int i =0 ; i < 4; i++) {
        updateFriction(tires[i]);

    }

    for (auto body : frontTires) {

        updateDrive(body);
    }

    updateSteering();
}


void CarEngine::updateDrive(b2Body *body) {

    //find desired speed
    float desiredSpeed = 0;

    if (keyboardManager->getKeyState(KeyboardManager::UP)) {
        desiredSpeed = maxForwardSpeed_;
    } else if (keyboardManager->getKeyState(KeyboardManager::DOWN)) {
        desiredSpeed = maxBackWardSpeed_;
    }

    //find current speed in forward direction
    b2Vec2 currentForwardNormal = body->GetWorldVector(b2Vec2(0, 1));
    float currentSpeed = b2Dot(getForwardVelocity(body), currentForwardNormal);

    //apply necessary force
    float force = 0;
    if (desiredSpeed > currentSpeed)
        force = maxDriveForce_;
    else if (desiredSpeed < currentSpeed)
        force = -maxDriveForce_;
    else
        return;

    body->ApplyForce(force * currentForwardNormal, body->GetWorldCenter(), true);
}

b2Vec2 CarEngine::getLateralVelocity(b2Body *body) {
    b2Vec2 currentRightNormal = body->GetWorldVector(b2Vec2(1, 0));
    return b2Dot(currentRightNormal, body->GetLinearVelocity()) * currentRightNormal;
}

void CarEngine::updateFriction(b2Body *body) {



    b2Vec2 impulse = body->GetMass() * -getLateralVelocity(body);
    body->ApplyLinearImpulse(impulse, body->GetWorldCenter(), true);
    body->ApplyAngularImpulse(0.1f * body->GetInertia() * -body->GetAngularVelocity(), true);

}

b2Vec2 CarEngine::getForwardVelocity(b2Body *body) {
    b2Vec2 currentRightNormal = body->GetWorldVector(b2Vec2(0, 1));
    return b2Dot(currentRightNormal, body->GetLinearVelocity()) * currentRightNormal;
}

void CarEngine::setTires(b2Body *tire0, b2Body *tire1, b2Body *tire2, b2Body *tire3) {

    tires[0] = tire0;
    tires[1] = tire1;
    tires[2] = tire2;
    tires[3] = tire3;
}

void CarEngine::updateSteering() {
    //TODO steering stuff

    float desiredAngle = 0;



    if(keyboardManager->getKeyState(KeyboardManager::LEFT)){
        desiredAngle += lockAngle;
        std::cerr << "TURNING LEFT " << std::endl;
    }

    if(keyboardManager->getKeyState(KeyboardManager::RIGHT)){
        desiredAngle -= lockAngle;
    }



    for(int i=0; i < 2; i++){
        b2RevoluteJoint * j = frontJoints_[i];
        float angleNow = j->GetJointAngle();
        float angleToTurn = desiredAngle - angleNow;
        angleToTurn = b2Clamp( angleToTurn, -turnPerTimeStep, turnPerTimeStep );
        float newAngle = angleNow + angleToTurn;
        j->SetLimits( newAngle, newAngle );
      //  j->SetLimits( 1.52, 1.52 );

    }


    
}

void CarEngine::setFrontJoints(std::vector<b2RevoluteJoint *> &frontJoints) {
    for(int i=0; i < 2; i++){
        frontJoints_[i] = frontJoints[i];
    }
}

void CarEngine::setBackJoints(std::vector<b2RevoluteJoint *> &backJoints) {
    for(int i=0; i < 2; i++){
        backJoints_[i] = backJoints[i];
    }
}

CarEngine::~CarEngine() {
    //first delete joints than bodies
}

void CarEngine::deleteJoints( Box2dManager * box2dManager_) {

    for(int i=0; i <2; i++){
        box2dManager_->getGameWorld()->DestroyJoint(frontJoints_[i]);
        box2dManager_->getGameWorld()->DestroyJoint(backJoints_[i]);
    }


}
