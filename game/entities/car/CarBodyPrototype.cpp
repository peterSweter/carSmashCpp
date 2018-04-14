//
// Created by peter on 4/14/18.
//

#include "CarBodyPrototype.h"

CarBodyPrototype::CarBodyPrototype(Json &json) {
    parseJson(json);
}

void CarBodyPrototype::parseJson(Json &json) {
    this->bodyID_ = json["boodyID"].get<std::string>();
}
