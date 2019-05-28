#ifndef OPTICRIB_CARDCOLLECTION_H
#define OPTICRIB_CARDCOLLECTION_H
#include "card.h"
#include <vector>

class CardCollection {
public:
    std::vector<Card> cards;
    CardCollection();
    void add_card(Card card);
    void transfer_card(int ix, CardCollection& target_col);
    void sort();
    void display();
};

#endif //OPTICRIB_CARDCOLLECTION_H