//
// Created by peter on 4/13/18.
//

#include "Box2dManager.h"

Box2dManager::Box2dManager() {
    b2Vec2 gravity(0,0);
    bool doSleep = true;
    this->gameWorld_ = std::make_shared<b2World>(gravity, doSleep);
}
