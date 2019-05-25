#include "player.h"
#include <vector>
#include <iostream>

Player::Player() {}

void Player::setrole(std::string r) {
    role = r;
}

std::string Player::getrole() {
    return role;
}

//std::vector<Card> Player::gethand() {
//    return hand;
//}


void Player::display_hand() {
    for (int i = 0; i < hand.size(); i++) {
        hand.at(i).display();
    }
}
