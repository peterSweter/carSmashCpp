//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARPROTOTYPE_H
#define CARSMASHCPP_CARPROTOTYPE_H


#include <map>
#include <Box2D/Box2D.h>
#include "CarPartPrototype.h"
#include "CarBodyPrototype.h"
#include "../../box2D/JointPrototype.h"
#include <nlohmann/json.hpp>
#include <set>

using Json = nlohmann::json;

class CarPrototype {
    std::string name_;
public:
    std::map<std::string, CarBodyPrototype> carBodyPrototypes_;
    std::vector<JointPrototype> joints_;

    CarPrototype(Json & json);
    void parseJson(Json & json);

};


#endif //CARSMASHCPP_CARPROTOTYPE_H