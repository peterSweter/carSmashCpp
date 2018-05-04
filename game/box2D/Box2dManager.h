//
// Created by peter on 4/13/18.
//

#ifndef CARSMASHCPP_BOX2DMANAGER_H
#define CARSMASHCPP_BOX2DMANAGER_H

#include <Box2D/Box2D.h>


class Box2dManager {
private:
    std::shared_ptr<b2World> gameWorld_;
    float32 timeStep_ = 1/20.0;      //the length of time passed to simulate (seconds)
    int32 velocityIterations_ = 8;   //how strongly to correct velocity
    int32 positionIterations_ = 3;   //how strongly to correct position


public:
    Box2dManager();
    void worldStep();
    b2Body * createBody(b2BodyDef * bodyDef);
    b2Fixture * createFixture(b2FixtureDef * fixtureDef);
    void queryWorld(b2QueryCallback * queryCallback, b2AABB);
};


#endif //CARSMASHCPP_BOX2DMANAGER_H
