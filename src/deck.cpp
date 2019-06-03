#include "deck.h"
#include "card.h"
#include <iterator>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <ncurses.h>

Deck::Deck() {
    int i = 0;
    for (int v = 1; v <= 13; v++) {
        for (int s = 1; s <= 4; s++) {
            const char * b;
            switch (s) {
                case 1:
                    b = "Hearts";
                    break;

                case 2:
                    b = "Spades";
                    break;

                case 3:
                    b = "Diamonds";
                    break;

                case 4:
                    b = "Clubs";
                    break;
            };

            Card card(v, b);
            add_card(card);
            i += 1;
        }
    }
}

void Deck::display_term() {
    int height, width, start_y, start_x;
    height = 8;
    width = 10;
    start_y = 5;
    start_x = 2;
    WINDOW * deck_win = newwin(height, width, start_y, start_x);
    box(deck_win, 0, 0);
    wprintw(deck_win, "Deck");
    refresh();
    wrefresh(deck_win);
}

void Deck::shuffle() {
    srand(time(0));
    std::random_shuffle(std::begin(cards), std::end(cards));
}

