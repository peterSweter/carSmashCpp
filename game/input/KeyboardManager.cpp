//
// Created by peter on 5/11/18.
//

#include <iostream>
#include "KeyboardManager.h"

KeyboardManager::KeyboardManager() :keys(256, false) {

}

void KeyboardManager::keyDown(int keyID) {
    if(keyID>=0 && keyID < keys.size()){
        keys[keyID] = true;
    }
}

void KeyboardManager::keyUp(int keyID) {
    if(keyID>=0 && keyID < keys.size()){
        keys[keyID] = false;
    }
}

void KeyboardManager::handleInput(int keyCode, char state) {
    std::cout << "handle input " << keyCode << " " << state << std::endl;

    if(state == 'u'){
        keyUp(keyCode);
    }else{
        keyDown(keyCode);
    }

}

bool KeyboardManager::getKeyState(int keyCode) {
    return keys[keyCode];
}
