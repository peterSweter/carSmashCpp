//
// Created by peter on 4/13/18.
//

#ifndef CARSMASHCPP_BOX2DMANAGER_H
#define CARSMASHCPP_BOX2DMANAGER_H

#include <Box2D/Box2D.h>


class Box2dManager {
private:
    std::shared_ptr<b2World> gameWorld_;

public:
    Box2dManager();
};


#endif //CARSMASHCPP_BOX2DMANAGER_H
