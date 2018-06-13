//
// Created by peter on 5/3/18.
//

#include <iostream>
#include "DataCollector.h"
#include "DataCollectableOnceI.h"

std::string DataCollector::getJsonData(b2Vec2 playerPosition, DataCollectableOnceI * callerObject) {
    jsonData_ = "{\"gameObjects\" : [ ";

    recenterAABB(playerPosition);

    this->updateCount_ = !updateCount_;

    auto jsonColectedPtr = callerObject->getJsonData(this, updateCount_);
    if(jsonColectedPtr){
        jsonData_+= jsonColectedPtr->dump();
    }

    box2dManager_->queryWorld(this,aabb_);

    jsonData_ +="]}";

    std::cout << "[DataCollector::getJsonData] collected json" << jsonData_ <<  std::endl;

    return jsonData_;


}

DataCollector::DataCollector(Box2dManager * box2dManager) :
      box2dManager_(box2dManager) {
    width_ = 200.f;
    height_= 200.f;

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

        if(jsonColectedPtr != nullptr ){


            jsonData_+=" , ";

            jsonData_+= jsonColectedPtr->dump();
        }

        std::cout << "[DataCollector::ReportFixture]  succesfull conversion" <<  std::endl;

    }else{
        std::cout << "[DataCollector::ReportFixture]  Unsuccesfull conversion" <<  std::endl;

    }

    // if return true query will keep going and find all fixtures in AABB area
    return true;
}
