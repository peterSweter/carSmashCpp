//
// Created by peter on 3/21/18.
//

#include "Player.h"
#include "Game.h"

void Player::update() {
    while(!sessionI_->getMessages()->empty()){
        auto  tmpMessage = std::move(sessionI_->getMessages()->front());
        sessionI_->getMessages()->pop();
        Game::threadOut << "Message from player" << std::endl;
        Game::threadOut << tmpMessage->dump() << std::endl;
    }
}

Player::Player(std::shared_ptr<SessionI> && sessionI) : sessionI_(std::move(sessionI)){
    Game::threadOut << "Created new player " << std::endl;
}
