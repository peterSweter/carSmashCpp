//
// Created by peter on 5/11/18.
//

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
