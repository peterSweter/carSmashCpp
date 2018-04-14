//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARPROTOTYPE_H
#define CARSMASHCPP_CARPROTOTYPE_H


#include <map>
#include <Box2D/Box2D.h>
#include "CarPartPrototype.h"
#include <nlohmann/json.hpp>

using Json = nlohmann::json;

class CarPrototype {
public:
    std::map<std::string, CarPartPrototype> carPartsPrototypes_;

    CarPrototype(Json & json);
    void parseJson(Json & json);

};


#endif //CARSMASHCPP_CARPROTOTYPE_H
