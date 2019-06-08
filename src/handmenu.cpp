#include "handmenu.h"
#include <iostream>

HandMenu::HandMenu(int player_num) {
    // Display window
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

// TODO  this should replace display_hand
void HandMenu::display_hand2(Hand& hand, int highlight) {
    for (int i = 0; i < hand.cards.size(); i++) {
        if (i == highlight) {
            wattron(win, A_STANDOUT);
            mvwprintw(win,  i + 1, 1, hand.cards[i].get_char());
            wattroff(win, A_STANDOUT);
        } else {
            mvwprintw(win,  i + 1, 1, hand.cards[i].get_char());
        }
    }
}

// TODO this is doing two things, handling the menu and returning the selection...
std::array<int, 2> HandMenu::display_discard_menu(Hand& hand) {
    // Highlight first menu item
    display_hand2(hand, 0);

    wrefresh(win);

    int ch, i= 0;
    int j = 0;
    std::array<int, 2> selected = {-1, -1};
    keypad(win , TRUE ); // enable keyboard input for the window.

    // Get ch, if it is not q, execute this block
    while(   (( ch = wgetch(win)) != 'q')){
        wclear(win);
        box(win, 0, 0);
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
            case KEY_RIGHT:
                selected[1] = selected[0]; // push the last element back
                selected[0] = i;
            case 119: // the w key
                i--;
                i = ( i<0 ) ? hand.cards.size() - 1: i;
                j = ( i == hand.cards.size()-1) ? 0: i+1;
                hand.change_order(j, i);
                break;
            case 115:
                i++;
                i = ( i>hand.cards.size() - 1 ) ? 0 : i;
                j = ( i == 0) ? hand.cards.size()-1: i-1;
                hand.change_order(j, i);
                break;
        }
        display_hand2(hand, i);
    }
    wrefresh(win);
    return selected;
}

void HandMenu::display_hand(Hand& hand, int player_num, bool hide) {
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