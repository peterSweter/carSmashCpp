//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYERSMANAGER_H
#define CARSMASHCPP_PLAYERSMANAGER_H


#include "../../networking/ListenerI.h"
#include "../../utils/ThreadSafeQueue.h"
#include "../../utils/ThreadSafeQueueI.h"
#include "Player.h"
#include "../entities/car/CarFactory.h"
#include <list>



//TODO choose container for storing Players - > suggested double linked list
//TODO consider creating gameObj class interface with update method

class PlayersManager : public ListenerObserverI {
private:

    std::list<std::shared_ptr<Player>> playersList_;

public:

    ThreadSafeQueue<std::shared_ptr<SessionI>> receivedSessionQ_;
    Box2dManager * box2dManager_;
    CarFactory carFactory_;

    PlayersManager(Box2dManager * box2dManager);

    void update();
    void pushNewSession(std::shared_ptr<SessionI> sessionI) override;

private:

    void createNewPlayer(std::shared_ptr<SessionI> sessionI);
};


#endif //CARSMASHCPP_PLAYERSMANAGER_H
