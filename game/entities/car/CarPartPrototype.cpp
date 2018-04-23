//
// Created by peter on 4/14/18.
//

#include "CarPartPrototype.h"

CarPartPrototype::CarPartPrototype(Json &json) {
    parseJson(json);
}

void CarPartPrototype::parseJson(Json &json) {

    this->carPartID_ = json["bodyID"].get<std::string>();
    this->durability_ =  json["durability"].get<double>();

    float restitution, friction, density;

    restitution = json["restitution"].get<float>();
    friction = json["friction"].get<float>();
    density = json["density"].get<float>();

    //shape of fixture

    if(json["shape"].get<std::string>() == "box"){

        float width, height;

        width = json["width"].get<float>();
        height = json["height"].get<float>();

        polygonShape_.SetAsBox(width, height);
        fixtureDef_.shape = &polygonShape_;

        fixtureDef_.density = density;
        fixtureDef_.friction = friction;
        fixtureDef_.restitution = restitution;

    }

    //visual

    color_ = json["color"].get<std::string>();

}

b2FixtureDef *CarPartPrototype::getFixtureDef() {
    return &fixtureDef_;
}
