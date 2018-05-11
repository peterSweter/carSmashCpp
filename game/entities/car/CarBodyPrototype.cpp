//
// Created by peter on 4/14/18.
//

#include <iostream>
#include "CarBodyPrototype.h"

CarBodyPrototype::CarBodyPrototype(Json &json) {
    parseJson(json);
}

void CarBodyPrototype::parseJson(Json &json) {


    this->bodyID_ = json["bodyID"].get<std::string>();
    std::cout << "[CarBodyPrototype] Loading body: " << bodyID_ <<  std::endl;

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
