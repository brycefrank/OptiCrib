#ifndef OPTICRIB_DECK_H
#define OPTICRIB_DECK_H
#include "card.h"
#include <vector>

class Deck {
public:
    std::vector<Card> cards;
    Deck();
    Card drawcard(int i);
    void shuffle();
};

#endif //OPTICRIB_DECK_H
