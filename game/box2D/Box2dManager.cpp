//
// Created by peter on 4/13/18.
//

#include "Box2dManager.h"

Box2dManager::Box2dManager() {
    b2Vec2 gravity(0.0,0.0);
    bool doSleep = true;
    this->gameWorld_ = std::make_shared<b2World>(gravity);
}

void Box2dManager::worldStep() {
    gameWorld_->Step(timeStep_, velocityIterations_, positionIterations_);
}

b2Body *Box2dManager::createBody(b2BodyDef * bodyDef) {
    return gameWorld_->CreateBody(bodyDef);
}

void Box2dManager::queryWorld(b2QueryCallback *queryCallback, b2AABB aabb) {
    this->gameWorld_->QueryAABB(queryCallback, aabb);
}
