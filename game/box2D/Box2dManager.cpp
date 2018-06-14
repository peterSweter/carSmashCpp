//
// Created by peter on 4/13/18.
//

#include "Box2dManager.h"
#include "../Game.h"

Box2dManager::Box2dManager() {
    b2Vec2 gravity(0.0,0.0);
    bool doSleep = true;
    this->gameWorld_ = std::make_shared<b2World>(gravity);

    this->gameWorld_->SetContactListener(&gameContactListener_);
}

void Box2dManager::worldStep() {
    gameWorld_->Step(Game::MS_PER_FRAME * 0.001, velocityIterations_, positionIterations_);
}

b2Body *Box2dManager::createBody(b2BodyDef * bodyDef) {
    return gameWorld_->CreateBody(bodyDef);
}

void Box2dManager::queryWorld(b2QueryCallback *queryCallback, b2AABB aabb) {
    this->gameWorld_->QueryAABB(queryCallback, aabb);
}

b2RevoluteJoint *Box2dManager::createJoint(b2RevoluteJointDef * revoluteJointDef) {
    return (b2RevoluteJoint*)gameWorld_->CreateJoint( revoluteJointDef );
}
