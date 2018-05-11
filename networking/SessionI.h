//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_SESSIONI_H
#define CARSMASHCPP_SESSIONI_H

#include <nlohmann/json.hpp>
#include <queue>
#include <mutex>
#include <boost/lockfree/queue.hpp>
#include "../utils/ThreadSafeQueue.h"
#include "../utils/ThreadSafeQueueI.h"

using Json = nlohmann::json;


class SessionI {
public:

    virtual void sendJSON(Json msg) = 0;
    virtual void sendJSON(std::shared_ptr<Json> msg) = 0;
    virtual ThreadSafeQueue<std::shared_ptr<Json>> * getMessages() = 0;
    virtual bool hasMessages() = 0;
};


#endif //CARSMASHCPP_SESSIONI_H
