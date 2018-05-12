//
// Created by peter on 4/14/18.
//

#include "Car.h"
#include "../../Game.h"
#include "CarPart.h"

Car::Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager * box2dManager) : box2dManager_(box2dManager) {

    // creating car from carProtorype

    // creating bodies:

    std::cout << "[Car] Constructor" << std::endl;

    for(auto carBodyPrototype : carPrototype->carBodyPrototypes_){

        std::string bodyName = carBodyPrototype.first;
        std::cout << "[Car] bodyName: " << bodyName <<  std::endl;

        b2Body * body  = box2dManager_->createBody(&carBodyPrototype.second->bodyDef_);
        body->SetUserData(this);

        //DataCollectableOnceI* testPtr = (DataCollectableOnceI*)(body->GetUserData());

        bodies_.insert(make_pair(bodyName, body));


        //creating carparts
        std::cout << "[Car] Creating car parts. " << std::endl;

        for(auto carPart : carBodyPrototype.second->carParts_){
            carParts_.emplace(carPart.first, std::make_shared<CarPart>(body, carPart.second.get()));

        }


        std::cout << "[Car] Created body. " <<  std::endl;

    }

    //joint boides
    //TODO joint bodies



}

std::shared_ptr<Json> Car::getJsonData() {

    std::cout << "[Car::getJsonData()] " << std::endl;

    //TODO consider caching more display data
    //TODO change to nlohman::josn and chache

    auto jsonData  = std::make_shared<Json>();

    jsonData->emplace("t", "car");
    jsonData->emplace("nick", player_->getNickname());

    Json bodiesJsonArray;


    for(auto b : bodies_){

        b2Body * body = b.second;

        Json bodyJsonObj;
        bodyJsonObj.emplace("x", body->GetPosition().x);
        bodyJsonObj.emplace("y", body->GetPosition().y);
        bodyJsonObj.emplace("angle", body->GetAngle());




        std::cout << "[Car] Inside bodies data collecting" << std::endl;

        Json fixturesArray;

        for (b2Fixture* f = b.second->GetFixtureList(); f; f = f->GetNext())
        {

            fixturesArray.push_back(*reinterpret_cast<CarPart*>(f->GetUserData())->getJsonData());
            std::cout << "[Car] succesfull conversion" << std::endl;


        }


        bodyJsonObj.emplace("fixtures", fixturesArray);
        bodiesJsonArray.push_back(bodyJsonObj);
    }

    jsonData->emplace("bodies", bodiesJsonArray);


    std::cout<< "[Car] Json parsing test" << jsonData->dump() << std::endl;

    return jsonData;
}

void Car::setPlayer(PlayerI *player) {
    this->player_ = player;

}

b2Vec2 Car::getPosition() {

    //TODO change this to variable
    return bodies_["chassis"]->GetPosition();
}

void Car::setKeyboardManager(KeyboardManager *keyboardManager) {
    this->keyboardManager_ = keyboardManager;
}

void Car::update() {
    //add force to body depending on keybord manager state
    if(keyboardManager_ == nullptr){
        Game::threadOut << "keyboard manager is not inited!\n";
    }
    // claculate power to apply
    b2Vec2 forceToApply(0,0);

    if(keyboardManager_->getKeyState(KeyboardManager::UP)){
        forceToApply.y+=10;
    }
    if(keyboardManager_->getKeyState(KeyboardManager::DOWN)){
        forceToApply.y-=10;
    }
    if(keyboardManager_->getKeyState(KeyboardManager::RIGHT)){
        forceToApply.y+=10;
    }
    if(keyboardManager_->getKeyState(KeyboardManager::LEFT)){
        forceToApply.y-=10;
    }
}
