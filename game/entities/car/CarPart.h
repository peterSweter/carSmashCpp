//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARPART_H
#define CARSMASHCPP_CARPART_H


#include <Box2D/Dynamics/b2Body.h>
#include "CarPartPrototype.h"
#include "../../dataCollector/DataCollectableI.h"
#include "../../box2D/interactionManager/InteractiveEntityPartA.h"


class CarPart  : public DataCollectableI, public InteractiveEntityPartA{
public:

    b2Body * body_;
    b2Fixture * fixture_;
    std::string color_;
    CarPartPrototype * carPartPrototype_;


    CarPart(b2Body * body , CarPartPrototype * carPartPrototype);

    std::shared_ptr<Json> getJsonData() override;
    ~CarPart();
};


#endif //CARSMASHCPP_CARPART_H
