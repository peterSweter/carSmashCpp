//
// Created by peter on 4/14/18.
//

#include <iostream>
#include "CarPrototype.h"

CarPrototype::CarPrototype(Json &json) {
    parseJson(json);
}

void CarPrototype::parseJson(Json &json) {

    name_ = json["name"].get<std::string>();
    std::cout << "[CarPrototype] Loading model: " << name_ << std::endl << std::flush;

    for(Json & bodyJson : json["bodies"]){

        carBodyPrototypes_.insert(std::make_pair(bodyJson["bodyID"].get<std::string>(), std::make_shared<CarBodyPrototype>(bodyJson)));
    }

    //joints

    for(Json & jointJson : json["joints"]){
        joints_.push_back(JointPrototype(jointJson));
    }

    health_ = json["maxHealth"].get<double>();

}

CarPrototype::~CarPrototype() {
    std::cout << "[CarPrototype] Destructor." << std::endl;
}
