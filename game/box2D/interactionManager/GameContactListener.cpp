//
// Created by peter on 6/13/18.
//

#include "GameContactListener.h"

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
}
