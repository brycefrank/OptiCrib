#include "player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ncurses.h>

// See:
 // https://stackoverflow.com/questions/12927169/how-can-i-initialize-c-object-member-variables-in-the-constructor
Player::Player(int num) : player_num(num), hand_menu(HandMenu(num)) {}


void Player::setrole(std::string r) {
    role = r;
}

std::string Player::getrole() {
    return role;
}

std::array<int, 2> Player::discard_phase() {
    return hand_menu.display_discard_menu(hand);
}

void Player::display_hand(bool hide) {
    hand_menu.display_hand(hand, player_num, hide);
}

void Player::random_discard(Hand crib) {
    // For now,  just  transfer the top two cards to the crib
    hand.transfer_card(0, crib);
    hand.transfer_card(0, crib);
}

