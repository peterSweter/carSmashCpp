//
// Created by peter on 5/11/18.
//

#ifndef CARSMASHCPP_KEYBOARDMANAGER_H
#define CARSMASHCPP_KEYBOARDMANAGER_H


#include <vector>

class KeyboardManager {
    std::vector<bool> keys;
public:

    KeyboardManager();
    void keyDown(int keyID);
    void keyUp(int keyID);


};


#endif //CARSMASHCPP_KEYBOARDMANAGER_H
