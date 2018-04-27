//
// Created by peter on 4/14/18.
//

#include <fstream>
#include "CarModels.h"

using Json = nlohmann::json;


CarModels::CarModels() {
    modelFiles_ = {"baseModel"};
    loadModels();
}



void CarModels::loadModels() {


    for(auto modelName : modelFiles_){

        std::string modelFileName  = modelDir_ + "/" + modelName + ".JSON";
        std::ifstream modelFile(modelFileName);
        Json json;
        modelFile >> json;

        models_.emplace(modelName, std::make_shared<CarPrototype>(json));


    }

}

std::shared_ptr<CarPrototype> CarModels::getModel(std::string modelID) {
    return models_.find(modelID)->second;
}
