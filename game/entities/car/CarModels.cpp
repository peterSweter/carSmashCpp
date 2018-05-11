//
// Created by peter on 4/14/18.
//

#include <fstream>
#include <nlohmann/json.hpp>
#include "CarModels.h"
#include "../../Game.h"

using Json = nlohmann::json;


CarModels::CarModels() {
    modelFiles_ = {"baseModel"};
    loadModels();
}



void CarModels::loadModels() {

    std::cout  <<  "[CarModels] Loading models. " << std::endl;



    for(auto modelName : modelFiles_){

        std::string modelFileName  = modelDir_ + "/" + modelName + ".JSON";
        std::ifstream modelFile(modelFileName);
        Json json;


        try {

            modelFile >> json;
        }catch (Json::parse_error e){

            std::cout << "[Car Models] Exception, wrong model car file: " << modelFileName << std::endl << e.what() << std::endl;
            exit(-1);
        }


        models_.emplace(modelName, std::make_shared<CarPrototype>(json));


    }

    std::cout <<  "[CarModels] Models loaded. " << std::endl;
}

std::shared_ptr<CarPrototype> CarModels::getModel(std::string modelID) {
    return models_.find(modelID)->second;
}
