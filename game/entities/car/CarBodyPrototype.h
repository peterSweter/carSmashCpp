//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARBODYPROTOTYPE_H
#define CARSMASHCPP_CARBODYPROTOTYPE_H


#include <map>
#include <Box2D/Box2D.h>
#include "nlohmann/json.hpp"
#include "CarPartPrototype.h"

using Json = nlohmann::json;

class CarBodyPrototype {
public:
    b2BodyDef bodyDef_;
    std::string bodyID_;
    std::map<std::string, CarPartPrototype> carParts_;

    explicit CarBodyPrototype(Json & json);
    void parseJson(Json & json);

};


#endif //CARSMASHCPP_CARBODYPROTOTYPE_H
