//
// Created by peter on 4/14/18.
//

#include "CarPrototype.h"

CarPrototype::CarPrototype(Json &json) {
    parseJson(json);
}

void CarPrototype::parseJson(Json &json) {

    name_ = json["name"].get<std::string>();
    for(Json & bodyJson : json["bodies"]){
        carBodyPrototypes_.insert(std::make_pair(bodyJson["carPartID"].get<std::string>(), CarBodyPrototype(bodyJson)));
    }

    //joints

    for(Json & jointJson : json["joints"]){
        joints_.push_back(JointPrototype(jointJson));
    }
}
