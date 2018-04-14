//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CARMODELS_H
#define CARSMASHCPP_CARMODELS_H


#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include "CarPrototype.h"

using Json = nlohmann::json;

class CarModels {
private:
    std::string modelDir_ = "carmodels";
public:

    std::vector<std::string> modelFiles_;
    std::map<std::string, std::shared_ptr<CarPrototype>> models_;

    CarModels();

    void loadModels();



};


#endif //CARSMASHCPP_CARMODELS_H
