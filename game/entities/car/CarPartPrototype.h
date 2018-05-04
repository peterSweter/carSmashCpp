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
private:
    b2PolygonShape polygonShape_;
    b2CircleShape circleShape_;
    std::string jsonDisplayData_;
public:
    const std::string * getJsonDisplayData() const;

public:
    std::string carPartID_;
    std::string color_;
    double durability_ = 0.0;
    b2FixtureDef fixtureDef_;

    CarPartPrototype(Json & json);
    void parseJson(Json & json);

    b2FixtureDef* getFixtureDef();

};


#endif //CARSMASHCPP_CARPARTPROTOTYPE_H
