#include "deck.h"
#include "card.h"
#include <iterator>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>
#include <vector>

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
            add_card(card);
            i += 1;
        }
    }
}

void Deck::shuffle() {
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(cards), std::end(cards), rng);
}

