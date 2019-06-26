#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "controller.h"
#include "player.h"
#include <iostream>

#include "deck.h"
#include "hand.h"

int main() {
    setlocale(LC_ALL, "");

    Deck d;
    Hand h;

    d.shuffle();

    for (int i = 0; i < 4; i++ ) {
        d.transfer_card(i, h);
    }

    h.count_hand(d.cards.at(0));

    //Controller c;
    //c.start();
    //int g = getch();
    //endwin();
	return 0;
}
