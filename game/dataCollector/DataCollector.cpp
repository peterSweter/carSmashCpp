//
// Created by peter on 5/3/18.
//

#include <iostream>
#include "DataCollector.h"
#include "DataCollectableOnceI.h"

std::string DataCollector::getJsonData(b2Vec2 playerPosition) {

    jsonData_ = "";
    recenterAABB(playerPosition);
    //TODO first append data of player's car
    this->updateCount_ = !updateCount_;


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
    std::cout << "[DataCollector::ReportFixture]" << std::endl;
    //TODO create interface for querying data
    //return true;
    if(DataCollectableOnceI * dataCollectable = reinterpret_cast<DataCollectableOnceI*>(fixture->GetBody()->GetUserData())){

        auto jsonColectedPtr = dataCollectable->getJsonData(this, updateCount_);

        if(jsonColectedPtr){
            jsonData_+= jsonColectedPtr->dump();
        }

        std::cout << "[DataCollector::ReportFixture]  succesfull conversion" <<  std::endl;

    }else{
        std::cout << "[DataCollector::ReportFixture]  Unsuccesfull conversion" <<  std::endl;

    }
    std::cout << "[DataCollector::ReportFixture] " << jsonData_ <<  std::endl;
    // if return true query will keep going and find all fixtures in AABB area
    return true;
}
