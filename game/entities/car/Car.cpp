//
// Created by peter on 4/14/18.
//

#include "Car.h"
#include "../../Game.h"

Car::Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager * box2dManager) : box2dManager_(box2dManager) {

    // creating car from carProtorype

    // creating bodies:

    for(auto carBodyPrototype : carPrototype->carBodyPrototypes_){

        std::string bodyName = carBodyPrototype.first;

        b2Body * body  = box2dManager_->createBody(&carBodyPrototype.second.bodyDef_);
        body->SetUserData(this);

        bodies_.emplace(bodyName, body);


        //creating carparts

        for(auto carPart : carBodyPrototype.second.carParts_){
            carParts_.emplace(carPart.first, CarPart(body, &carPart.second));

        }



    }

    //joint boides
    //TODO joint bodies



}

std::string Car::getJsonData() {

    //TODO consider caching more display data

    std::string jsonDisplaydata = "{ \"t\" : \"car\", \"nick\" : \""+ player_->getNickname() +  " \",  \"bodies\" : [ ";

    for(auto b : bodies_){
        b2Body * body = b.second;
        jsonDisplaydata += "{ \" x\" : "+ std::to_string(body->GetPosition().x)+  " \"y\" : " + std::to_string(body->GetPosition().y) + ", ";
        jsonDisplaydata += "\"angle\"" + std::to_string(body->GetAngle()) + ",";
        jsonDisplaydata += "\"fixtures\" : [";

        for (b2Fixture* f = b.second->GetFixtureList(); f; f = f->GetNext())
        {
            jsonDisplaydata+= static_cast<CarPart*>(f->GetUserData())->getJsonData();
            if(f->GetNext()){
                jsonDisplaydata+=" , ";
            }
        }

        // end of fixtures
        jsonDisplaydata += "]";

    }

    //end of bodies obj array
    jsonDisplaydata += " ]}";

    return jsonDisplaydata;
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
