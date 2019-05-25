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

//std::vector<Card> Player::gethand() {
//    return hand;
//}


void Player::display_hand() {
    for (int i = 0; i < hand.size(); i++) {
        hand.at(i).display();
    }

}

Card* Player::discard_phase() {
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
        discard[i] = hand.at(remove[i]);
        hand.erase(hand.begin() + remove[i]);
    }

    for (int i = 0; i < hand.size(); i++) {
        hand.at(i).display();
    }

    return discard;
}

Card* Player::random_discard() {
    // TODO add AI here...for now this just discards the first two
    static Card discard[2];
    discard[0] = hand.at(0);
    discard[1] = hand.at(1);
    hand.erase(hand.begin());
    hand.erase(hand.begin() + 1);

    return discard;

}