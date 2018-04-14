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

    if(json["type"].get<std::string>() == "b2_dynamicBody"){
        this->bodyDef_.type = b2_dynamicBody;
    }else if(json["type"].get<std::string>() == "b2_saticBody"){
        this->bodyDef_.type = b2_staticBody;
    }

    b2Fixture * test;




}
