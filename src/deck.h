#ifndef OPTICRIB_DECK_H
#define OPTICRIB_DECK_H
#include "card.h"
#include "cardcollection.h"
#include <vector>


class Deck : public CardCollection {
public:
    Deck();
    void shuffle();
    void display_term();
};

#endif //OPTICRIB_DECK_H
