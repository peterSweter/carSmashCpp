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
    void keyDown(int keyCode);
    void keyUp(int keyCode);

    bool getKeyState(int keyCode);

    static const int LEFT = 37;
    static const int UP = 40;
    static const int RIGHT = 39;
    static const int DOWN = 38;

    void handleInput(int keyCode, char state);
};


#endif //CARSMASHCPP_KEYBOARDMANAGER_H
