#ifndef OPTICRIB_CARDCOLLECTION_H
#define OPTICRIB_CARDCOLLECTION_H
#include "card.h"
#include <vector>

class CardCollection {
protected:
    std::vector<Card> cards;
public:
    CardCollection();
    void add_card(Card card);
    Card get_card(int ix);
    void transfer_card(int ix, CardCollection target_col);
    void sort();
    void display();
};

#endif //OPTICRIB_CARDCOLLECTION_H