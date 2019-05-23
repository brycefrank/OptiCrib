#include "Deck.h"
#include "Card.h"
#include <iterator>
#include <algorithm>
#include <string>

Deck::Deck() {
    int i = 0;
    for (int v = 1; v <= 13; v++) {
        for (int s = 1; s <= 4; s++) {
            std::string b;
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
            cards[i] = card;
            i += 1;
        }
    }
}

Card Deck::getcard(int i) {
    return cards[i];
}

int * Deck::shuffle() {
    static int order[52];
    std::fill_n(order, 52, -1);
    srand (time(NULL));

    int i = 0;
    while (i < 52) {
        int rand_num = rand() % 52;
        int *finder = std::find(std::begin(order), std::end(order), rand_num);

        if (finder == std::end(order)){
            // This number is not in the array yet
            order[i] = rand_num;
            i+=1;
        }
    }

    return order;
}
