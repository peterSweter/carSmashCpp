//
// Created by peter on 5/3/18.
//

#ifndef CARSMASHCPP_DATACOLLECTOR_H
#define CARSMASHCPP_DATACOLLECTOR_H


#include <Box2D/Collision/b2Collision.h>
#include <Box2D/Box2D.h>
#include "DataCollectableI.h"
#include "../box2D/Box2dManager.h"


class Player;

class DataCollector : b2QueryCallback{
    //should have interface to boc2dManager for world queries purpose

private:
    b2AABB aabb_;
    float32 width_;
    float32 height_;
    Box2dManager * box2dManager_;
    std::string jsonData_;
    bool updateCount_ = false;


public:
    //TODO change player to data collector
    std::string getJsonData(b2Vec2);
    void recenterAABB(b2Vec2);

    DataCollector(Box2dManager * box2dManager);

    bool ReportFixture(b2Fixture *fixture) override;


};


#endif //CARSMASHCPP_DATACOLLECTOR_H
