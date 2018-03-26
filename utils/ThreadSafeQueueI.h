//
// Created by peter on 3/26/18.
//

#ifndef CARSMASHCPP_THREADSAFEQUEUEI_H
#define CARSMASHCPP_THREADSAFEQUEUEI_H

template <typename T>
class ThreadSafeQueueIT {
public:
    virtual void push( const T& value ) = 0;
    virtual void push( T&& value ) = 0;



    virtual bool empty() = 0;
    virtual  T& front() = 0;
    virtual void pop() =0;

};




#endif //CARSMASHCPP_THREADSAFEQUEUEI_H
