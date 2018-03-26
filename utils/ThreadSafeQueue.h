//
// Created by peter on 3/26/18.
//

#ifndef CARSMASHCPP_THREADSAFEQUEUE_H
#define CARSMASHCPP_THREADSAFEQUEUE_H


#include <mutex>
#include <queue>
#include "ThreadSafeQueueI.h"
#include "../networking/SessionI.h"

template <class T>
class ThreadSafeQueue : public ThreadSafeQueueIT<T>{

private:
    std::mutex myMutex_;
    std::queue<T> queue_;

public:

    ThreadSafeQueue() = default;

    void push(const T &value) override{
        std::lock_guard<std::mutex>(this->myMutex_);
        queue_.push(value);
    }

    void push(T &&value) override{
        std::lock_guard<std::mutex>(this->myMutex_);
        queue_.push(value);
    }



    bool empty() override{
        std::lock_guard<std::mutex>(this->myMutex_);
        return queue_.empty();
    }

    T &front() override{
        std::lock_guard<std::mutex>(this->myMutex_);
        return queue_.front();
    }

    void pop() override{
        std::lock_guard<std::mutex>(this->myMutex_);
        queue_.pop();
   }


};

/*
template <typename T>
void ThreadSafeQueue<T>::push(const T &value) {
    std::lock_guard<std::mutex>(this->myMutex_);
    queue_.push(value);
}
template <typename T>
void ThreadSafeQueue<T>::push(T &&value) {
    std::lock_guard<std::mutex>(this->myMutex_);
    queue_.push(value);
}

template <typename T>
bool ThreadSafeQueue<T>::empty() {
    std::lock_guard<std::mutex>(this->myMutex_);
    return queue_.empty();
}
template <typename T>
T &ThreadSafeQueue<T>::front() {
    std::lock_guard<std::mutex>(this->myMutex_);
    return queue_.front();
}
template <typename T>
void ThreadSafeQueue<T>::pop() {
    std::lock_guard<std::mutex>(this->myMutex_);
    queue_.pop();
}*/




#endif //CARSMASHCPP_THREADSAFEQUEUE_H
