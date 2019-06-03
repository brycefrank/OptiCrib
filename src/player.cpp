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

void Player::discard_phase() {
    // Highlight first menu item

    for (int i = 0; i < hand.cards.size(); i++) {
        if (i == 0) {
            wattron(win, A_STANDOUT);
        } else {
            wattroff(win, A_STANDOUT);
        }
        mvwprintw(win,  i + 1, 1, hand.cards[i].get_char());
    }

    wrefresh(win);

    int ch, i = 0;
    keypad(win , TRUE ); // enable keyboard input for the window.

    // get the input
    while(( ch = wgetch(win)) != 'q'){

        mvwprintw( win, i+1, 1, hand.cards[i].get_char());
        // use a variable to increment or decrement the value based on the input.
        switch( ch ) {
            case KEY_UP:
                i--;
                i = ( i<0 ) ? hand.cards.size() - 1: i;
                break;
            case KEY_DOWN:
                i++;
                i = ( i>hand.cards.size() - 1 ) ? 0 : i;
                break;
        }
        // now highlight the next item in the list.
        wattron( win, A_STANDOUT );
        mvwprintw( win, i+1, 1, hand.cards[i].get_char());
        wattroff( win, A_STANDOUT );
    }

}

void Player::random_discard(Hand crib) {
    // For now,  just  transfer the top two cards to the crib
    hand.transfer_card(0, crib);
    hand.transfer_card(0, crib);
}

void Player::display_hand_window() {
    if (player_num == 1) {
        win = newwin(8, 20, 14, 12);
        box(win, 0, 0);
        wprintw(win, "Player Hand");
        refresh();
        wrefresh(win);
    }

    else {
        win = newwin(8, 20, 1, 12);
        box(win, 0, 0);
        wprintw(win, "Opponent Hand");
        wrefresh(win);
    }
}

void Player::display_hand(bool hide) {
    if (player_num == 1) {
        wclear(win);
        box(win, 0, 0);
        wprintw(win, "Player Hand");
        for (int i = 0; i < hand.cards.size(); i++){
            mvwprintw(win,  i + 1, 1, hand.cards[i].get_char());
        }
    }
    else {
        wclear(win);
        box(win, 0, 0);
        wprintw(win, "Opponent Hand");
        for (int i = 0; i < hand.cards.size(); i++){

            if (hide) {
                mvwprintw(win,  i + 1, 1, "--");
            } else {
                mvwprintw(win,  i + 1, 1, hand.cards[i].get_char());
            }
        }
    }
    wrefresh(win);
}
