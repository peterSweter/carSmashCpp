//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARPARTPROTOTYPE_H
#define CARSMASHCPP_CARPARTPROTOTYPE_H


#include <map>
#include <Box2D/Box2D.h>
#include "nlohmann/json.hpp"

using Json = nlohmann::json;

class CarPartPrototype {
public:
    std::string carPartID_;
    double durability_ = 0.0;
    std::vector<b2FixtureDef> fixtureDefinitions_;

    CarPartPrototype(Json & json);
    void parseJson(Json & json);

};


#endif //CARSMASHCPP_CARPARTPROTOTYPE_H
