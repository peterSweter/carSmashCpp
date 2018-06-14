//
// Created by peter on 6/13/18.
//

#include "GameContactListener.h"
#include "InteractiveEntityPartA.h"

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
    b2ContactListener::PostSolve(contact, impulse);
    //TODO calculate collision force

    auto fixA = contact->GetFixtureA();
    auto fixB = contact->GetFixtureB();


    if(fixA->GetUserData() != nullptr && fixB->GetUserData() != nullptr){
        auto entityA  = static_cast<InteractiveEntityPartA*>(fixA->GetUserData());
        auto entityB  = static_cast<InteractiveEntityPartA*>(fixB->GetUserData());

        if(entityA->colideWidth(entityB)){
            entityA->dealDamage(entityB, impulse->normalImpulses[0]);
        }

        if(entityB->colideWidth(entityA)){
            entityB->dealDamage(entityA, impulse->normalImpulses[0]);
        }
    }


}
