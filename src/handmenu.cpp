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
void HandMenu::display_hand(Hand& hand, int highlight, bool hide) {
    wclear(win);
    box(win, 0, 0);
    for (int i = 0; i < hand.cards.size(); i++) {
        const char * disp;
        if (hide) {
            disp = "--";
        } else {
            disp = hand.cards[i].get_char();
        }

        if (i == highlight) {
            wattron(win, A_STANDOUT);
            mvwprintw(win,  i + 1, 1, disp);
            wattroff(win, A_STANDOUT);
        } else {
            mvwprintw(win,  i + 1, 1, disp);
        }
    }
}

bool HandMenu::validate_selection(std::vector<int> selection) {
    if (selection[0] == selection[1]) {
        return false;
    } else if ( (selection[0] == -1) || (selection[1] == -1) ){
        return false;
    } else {
        return true;
    }
}


// TODO this is doing two things, handling the menu and returning the selection...
std::vector<int> HandMenu::get_selection(Hand& hand, int length) {
    // Highlight first menu item
    display_hand(hand, 0);

    wrefresh(win);

    int ch, i= 0;
    int j = 0;

    std::vector<int> selected(length, -1);

    keypad(win , TRUE ); // enable keyboard input for the window.

    // Get ch, if it is not q, execute this block
    while(   (( ch = wgetch(win)) != 'q')){
        wclear(win);
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
                // Push back all elements
                for (int j = 0; j < length - 1; j++) {
                    selected[length - j - 1] = selected[length - j - 2];
                }
                selected[0] = i;

                break;
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
        display_hand(hand, i);
    }

    wrefresh(win);
    if (validate_selection(selected)) {
        return selected;
    } else {
        get_selection(hand, length);
    }

}

