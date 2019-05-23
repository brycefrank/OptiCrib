#ifndef OPTICRIB_DECK_H
#define OPTICRIB_DECK_H
#include "Card.h"

class Deck {
public:
    Card cards[52];
    Deck();
    Card getcard(int i);
    int * shuffle();
};

#endif //OPTICRIB_DECK_H
