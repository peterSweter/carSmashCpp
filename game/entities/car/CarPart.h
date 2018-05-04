//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARPART_H
#define CARSMASHCPP_CARPART_H


#include <Box2D/Dynamics/b2Body.h>
#include "CarPartPrototype.h"
#include "../../dataCollector/DataCollectableI.h"


class CarPart  : public DataCollectableI{
public:
    b2Body * body_;
    b2Fixture * fixture_;
    double durability_;
    std::string color_;
    CarPartPrototype * carPartPrototype_;


    //TODO implement get data interface and create such an interface


    CarPart(b2Body * body , CarPartPrototype * carPartPrototype);

    std::string getJsonData() override;
};


#endif //CARSMASHCPP_CARPART_H
