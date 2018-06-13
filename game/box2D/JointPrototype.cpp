//
// Created by peter on 4/14/18.
//

#include "JointPrototype.h"

void JointPrototype::parseJson(Json &json) {

    bodyAID_ = json["bodyAID"].get<std::string>();
    bodyBID_ = json["bodyBID"].get<std::string>();

    localAnchorA_.x = json["localAnchorAx"].get<float>();
    localAnchorA_.y = json["localAnchorAy"].get<float>();
    localAnchorB_.x = json["localAnchorBx"].get<float>();
    localAnchorB_.y = json["localAnchorBy"].get<float>();

    referenceAngle_ = json["referenceAngle"].get<float>();
}

JointPrototype::JointPrototype(Json &json) {
    parseJson(json);
}
