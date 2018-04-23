//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_JOINTPROTOTYPE_H
#define CARSMASHCPP_JOINTPROTOTYPE_H

#include <string>
#include <Box2D/Common/b2Math.h>
#include <nlohmann/json.hpp>

using Json = nlohmann::json;

class JointPrototype {
public:
    std::string bodyAID_, bodyBID_;
    b2Vec2 localAnchorA_, localAnchorB_;

    JointPrototype(Json & json);
    void parseJson(Json & json);


};


#endif //CARSMASHCPP_JOINTPROTOTYPE_H
