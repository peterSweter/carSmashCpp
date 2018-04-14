//
// Created by peter on 4/14/18.
//

#include "CarPrototype.h"

CarPrototype::CarPrototype(Json &json) {
    parseJson(json);
}

void CarPrototype::parseJson(Json &json) {
    for(Json & bodyJson : json["bodies"]){
        this->carPartsPrototypes_.emplace(bodyJson["carPartID"].get<std::string>(), CarPartPrototype(bodyJson));
    }
}
