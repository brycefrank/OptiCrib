#include "player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ncurses.h>

Player::Player(int num) {
    player_num = num;
}


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

void Player::display_hand_window() {
    if (player_num == 1) {
        WINDOW * p_h = newwin(8, 20, 14, 12);
        box(p_h, 0, 0);
        wprintw(p_h, "Player Hand");
        refresh();
        wrefresh(p_h);
    }

    else {
        WINDOW * o_h = newwin(8, 20, 1, 12);
        box(o_h, 0, 0);
        wprintw(o_h, "Opponent Hand");
        wrefresh(o_h);
    }

}
