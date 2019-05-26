#include "player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

Player::Player() {}

void Player::setrole(std::string r) {
    role = r;
}

std::string Player::getrole() {
    return role;
}

void Player::discard_phase(Hand crib) {
    int first_discard;
    int second_discard;

    //TODO inputs should be checked to be in the range of hand indices
    std::cout << "First discard: ";
    std::cin >> first_discard;
    std::cout << "Second discard: ";
    std::cin >> second_discard;

    int remove[2];
    static Card discard[2];
    remove[0] = first_discard;
    remove[1] = second_discard;
    std::sort(std::begin(remove), std::end(remove), std::greater<int>());
    for (int i = 0; i < 2; i++) {
        hand.transfer_card(remove[i], crib);
    }
}

void Player::random_discard(Hand crib) {
    // For now,  just  transfer the top two cards to the crib
    hand.transfer_card(0, crib);
    hand.transfer_card(0, crib);
}

