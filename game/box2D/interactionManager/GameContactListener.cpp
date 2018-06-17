//
// Created by peter on 6/13/18.
//

#include <iostream>
#include "GameContactListener.h"
#include "InteractiveEntityPartA.h"
#include "../../entities/EntityI.h"
#include "../../entities/car/CarPart.h"

void GameContactListener::BeginContact(b2Contact *contact) {
    b2ContactListener::BeginContact(contact);
}

void GameContactListener::EndContact(b2Contact *contact) {
    b2ContactListener::EndContact(contact);
}

void GameContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold) {
    b2ContactListener::PreSolve(contact, oldManifold);
}

void GameContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) {
    //b2ContactListener::PostSolve(contact, impulse);
    //TODO calculate collision force



    b2Fixture * fixA = contact->GetFixtureA();
    b2Fixture * fixB = contact->GetFixtureB();


    if(fixA->GetUserData() && fixB->GetUserData()){
        float impuls =  ((impulse->normalImpulses[0] + impulse->normalImpulses[1]));
        std::cerr << impuls << "/n";

        auto entityA  = static_cast<CarPart*>(fixA->GetUserData());
        auto entityB  = static_cast<CarPart*>(fixB->GetUserData());

        if(entityA->colideWidth(entityB)){
            entityA->dealDamage(entityB, (impulse->normalImpulses[0] + impulse->normalImpulses[1]) * 5 );
        }

        if(entityB->colideWidth(entityA)){
            entityB->dealDamage(entityA, (impulse->normalImpulses[0] + impulse->normalImpulses[1]) * 5);
        }
    }


}
