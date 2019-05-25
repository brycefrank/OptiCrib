#include "deck.h"
#include "card.h"
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

Deck::Deck() {
    cards.reserve(52);

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
            cards.push_back(card);
            i += 1;
        }
    }
}

Card Deck::drawcard(int i) {
    Card card = cards[i];
    cards.erase(cards.begin() + i);

    return card;
}

void Deck::shuffle() {
    int order[52];
    std::fill_n(order, 52, -1);
    srand (time(NULL));

    //Card shuffled[52]; // temp array of cards
    // Now, construct the shuffled order
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

    // Use the order to re-arrange the cards array
    for (int i = 0; i < 52; i++) {
        cards[i] = cards[order[i]];
    }

}
