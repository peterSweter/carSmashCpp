//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_SESSIONI_H
#define CARSMASHCPP_SESSIONI_H

#include <nlohmann/json.hpp>
#include <queue>
#include <mutex>

using Json = nlohmann::json;

class SessionI {
public:

    virtual void sendJSON(Json msg) = 0;
    virtual std::queue<Json> & getMessages() = 0;
    virtual std::mutex & getMutex() = 0;
    virtual bool hasMessages() = 0;
};


#endif //CARSMASHCPP_SESSIONI_H
