//
// Created by peter on 6/13/18.
//

#ifndef CARSMASHCPP_GAMECONTACTLISTENER_H
#define CARSMASHCPP_GAMECONTACTLISTENER_H


#include <Box2D/Box2D.h>

class GameContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact *contact) override;

    void EndContact(b2Contact *contact) override;

    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;

    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;

};


#endif //CARSMASHCPP_GAMECONTACTLISTENER_H
