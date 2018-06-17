//
// Created by peter on 4/14/18.
//

#include "Car.h"
#include "../../Game.h"
#include "CarPart.h"
#include "../../../utils/Utilities.h"
#include "../../box2D/interactionManager/collideMasks.h"

Car::Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager *box2dManager) : box2dManager_(box2dManager) {

    // creating car from carProtorype

    // creating bodies:



    for (auto carBodyPrototype : carPrototype->carBodyPrototypes_) {

        std::string bodyName = carBodyPrototype.first;
        std::cout << "[Car] bodyName: " << bodyName << std::endl;

        b2Body *body = box2dManager_->createBody(&carBodyPrototype.second->bodyDef_);
        body->SetUserData(this);

        //DataCollectableOnceI* testPtr = (DataCollectableOnceI*)(body->GetUserData());

        bodies_.insert(make_pair(bodyName, body));


        //creating carparts


        for (auto carPart : carBodyPrototype.second->carParts_) {

            auto tmpCarPart = std::make_shared<CarPart>(body, carPart.second.get());
            tmpCarPart->setEntity(this);
            carParts_.emplace(carPart.first,tmpCarPart );

        }



    }

    this->carEngine_.setFrontTires(bodies_["tire3"], bodies_["tire4"]);
    this->carEngine_.setTires(bodies_["tire3"], bodies_["tire4"], bodies_["tire1"], bodies_["tire2"]);



    //joint boides
    //TODO joint bodies fix this, create mechanism for deleting this joint in the future
    //TODO WARNING MEMORY LEAK MEMORY HAZARD WOLOLO

    std::vector<b2RevoluteJoint *> frontJoints;
    std::vector<b2RevoluteJoint *> backJoints;

    for (JointPrototype &jointPrototype : carPrototype->joints_) {

        b2RevoluteJointDef revoluteJointDef;

        if(!bodies_.count(jointPrototype.bodyAID_) || !bodies_.count(jointPrototype.bodyAID_) ){
            std::cout << "error body is not in the body set" << std::endl;
        }

        revoluteJointDef.bodyA = bodies_[jointPrototype.bodyAID_];
        revoluteJointDef.bodyB = bodies_[jointPrototype.bodyBID_];

        revoluteJointDef.collideConnected = false;
        revoluteJointDef.referenceAngle = jointPrototype.referenceAngle_ * DEGTORAD;
        revoluteJointDef.enableLimit = true;
        //revoluteJointDef.lowerAngle =  0 * DEGTORAD;
        //revoluteJointDef.upperAngle =  0 * DEGTORAD;

        revoluteJointDef.localAnchorA.Set(jointPrototype.localAnchorA_.x, jointPrototype.localAnchorA_.y);
        revoluteJointDef.localAnchorB.Set(jointPrototype.localAnchorB_.x, jointPrototype.localAnchorB_.y);

        auto tmpJoint  = box2dManager_->createJoint(&revoluteJointDef);

        if(jointPrototype.bodyBID_ == "tire3" || jointPrototype.bodyBID_ == "tire4"){
            frontJoints.push_back(tmpJoint);
        }else{
            backJoints.push_back(tmpJoint);
        }

        std::cout << "joint check: " << jointPrototype.bodyAID_ << " " << jointPrototype.bodyBID_ << " "
                  << jointPrototype.localAnchorA_.x << " " << jointPrototype.localAnchorA_.y << " "
                  << jointPrototype.localAnchorB_.x<< " " << jointPrototype.localAnchorB_.y << std::endl;

    }

    this->carEngine_.setFrontJoints(frontJoints);
    this->carEngine_.setBackJoints(backJoints);

    //TODO debug joints :/
   // exit(-1);


    this->setHealth(carPrototype->health_);
    this->maxHealth = carPrototype->health_;
    this->setMyMask(collideMask::car);
    this->setMaskCollideWith(collideMask::car);

}

std::shared_ptr<Json> Car::getJsonData() {



    //TODO consider caching more display data
    //TODO change to nlohman::josn and chache

    auto jsonData = std::make_shared<Json>();

    jsonData->emplace("t", "car");
    jsonData->emplace("nick", player_->getNickname());
    jsonData->emplace("x", getPosition().x);
    jsonData->emplace("y", getPosition().y);
    jsonData->emplace("hp", this->getHealth()/this->maxHealth);

    Json bodiesJsonArray;


    for (auto b : bodies_) {

        b2Body *body = b.second;

        Json bodyJsonObj;
        bodyJsonObj.emplace("x", body->GetPosition().x);
        bodyJsonObj.emplace("y", body->GetPosition().y);
        bodyJsonObj.emplace("angle", body->GetAngle());


        Json fixturesArray;

        for (b2Fixture *f = b.second->GetFixtureList(); f; f = f->GetNext()) {

            fixturesArray.push_back(*reinterpret_cast<CarPart *>(f->GetUserData())->getJsonData());
        }


        bodyJsonObj.emplace("fixtures", fixturesArray);
        bodiesJsonArray.push_back(bodyJsonObj);
    }

    jsonData->emplace("bodies", bodiesJsonArray);


  //  std::cout << "[Car] Json parsing test" << jsonData->dump() << std::endl;

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
    this->carEngine_.setKeyboardManager(keyboardManager);
}

void Car::update() {
    //add force to body depending on keybord manager state
    if (keyboardManager_ == nullptr) {
        Game::threadOut << "keyboard manager is not inited!\n";
    }

   carEngine_.update();
}

void Car::dealDamage(InteractiveEntityPartA *entity, double dmg) {

    score_ += entity->takeDamage(dmg * this->getDamageFactor());

    std::cerr << score_ << std::endl;
}

Car::~Car() {

    std::cout << "[Car] Deconstructor." << std::endl;

    this->carEngine_.deleteJoints(this->box2dManager_);

    for(auto it : bodies_){
        box2dManager_->getGameWorld()->DestroyBody(it.second);
    }

}

double Car::getScore() {
    return score_;
}

