//
// Created by peter on 3/31/18.
//

#ifndef CARSMASHCPP_GAMESESSION_H
#define CARSMASHCPP_GAMESESSION_H


#include "../../networking/SessionI.h"

class GameSession {
    int x = 0,y =0;
public:
    void handleInput(std::shared_ptr<Json> msg);
    std::map<std::string, std::string> getData();
    void update();
};


#endif //CARSMASHCPP_GAMESESSION_H
