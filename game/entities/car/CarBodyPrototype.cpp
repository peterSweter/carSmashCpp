//
// Created by peter on 4/14/18.
//

#include "CarBodyPrototype.h"

CarBodyPrototype::CarBodyPrototype(Json &json) {
    parseJson(json);
}

void CarBodyPrototype::parseJson(Json &json) {

    this->bodyID_ = json["boodyID"].get<std::string>();

    if(json["type"].get<std::string>() == "b2_dynamicBody"){
        bodyDef_.type = b2_dynamicBody;
    }

    //create car parts;

    Json & fixtures  = json["fixtures"];

    for(auto & fixtureJson : fixtures){
        std::string carPartID = fixtureJson["carPartID"].get<std::string>();
        carParts_.emplace(carPartID, CarPartPrototype(fixtureJson));
    }




}
