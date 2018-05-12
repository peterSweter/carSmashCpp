//
// Created by peter on 4/14/18.
//

#include <iostream>
#include "CarPartPrototype.h"

CarPartPrototype::CarPartPrototype(Json &json) : polygonShape_() {
    parseJson(json);
}

void CarPartPrototype::parseJson(Json &json) {

    //TODO importand debug creating json to send, maybe switch to nolhamn json due to more readable code and then generate static to_str from that ? (1)

    jsonDisplayData_ = "{";

    this->carPartID_ = json["carPartID"].get<std::string>();
    this->durability_ = json["durability"].get<double>();

    float restitution, friction, density, x, y;

    restitution = json["restitution"].get<float>();
    friction = json["friction"].get<float>();
    density = json["density"].get<float>();

    //shape of fixture
    std::string shapeType = json["shape"].get<std::string>();

    jsonDisplayData_ += " \"shape\" : \"" + shapeType + "\" ";

    if (shapeType == "box") {

        std::cout << "[CarPartPrototype] Creating box shaped carPart. " << std::endl;


        float width, height;

        width = json["width"].get<float>();
        height = json["height"].get<float>();

        jsonDisplayData_ += " , \"width\" : \"" + std::to_string(width) + "\" ";
        jsonDisplayData_ += " , \"height\" : \"" + std::to_string(height) + "\" ";

        polygonShape_.SetAsBox(width, height);
        fixtureDef_.shape = &polygonShape_;

      /*  b2PolygonShape * polygonShape = new b2PolygonShape();
        polygonShape->SetAsBox(width, height);
        fixtureDef_.shape = polygonShape;
       */

        fixtureDef_.density = density;
        fixtureDef_.friction = friction;
        fixtureDef_.restitution = restitution;

    }

    //visual

    color_ = json["color"].get<std::string>();
    jsonDisplayData_ += " , \"color\" : \"" + color_ + "\" ";

    //close json string

    jsonDisplayData_ += "}";

}

b2FixtureDef *CarPartPrototype::getFixtureDef() {

    std::cout << "[CarPartPrototype] getFixtureDef" << std::endl;
    return &fixtureDef_;
}

const std::string *CarPartPrototype::getJsonDisplayData() const {
    return &jsonDisplayData_;
}

CarPartPrototype::~CarPartPrototype() {
    std::cout << "[CarPartPrototype] Deconstructor id: " <<  carPartID_ << std::endl;
}
