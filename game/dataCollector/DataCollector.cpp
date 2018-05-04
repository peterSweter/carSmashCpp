//
// Created by peter on 5/3/18.
//

#include "DataCollector.h"
#include "DataCollectableOnceI.h"

std::string DataCollector::getJsonData(Player * player, b2Vec2 playerPosition, bool updateCount) {

    jsonData_ = "";
    recenterAABB(playerPosition);
    //TODO first append data of player's car
    this->player_ = player;
    this->updateCount_ = updateCount;


    box2dManager_->queryWorld(this,aabb_);


    return jsonData_;


}

DataCollector::DataCollector(Box2dManager * box2dManager) :
      box2dManager_(box2dManager) {
    width_ = 10.f;
    height_= 10.f;

}

void DataCollector::recenterAABB(b2Vec2 playerPos) {


    aabb_.lowerBound = b2Vec2(playerPos.x - width_, playerPos.y - height_);
    aabb_.upperBound = b2Vec2(playerPos.x + width_, playerPos.y + height_);

}

bool DataCollector::ReportFixture(b2Fixture *fixture) {

    //TODO create interface for querying data
    jsonData_+= static_cast<DataCollectableOnceI*>(fixture->GetBody()->GetUserData())->getJsonData(player_, updateCount_);
    // if return true query will keep going and find all fixtures in AABB area
    return true;
}
