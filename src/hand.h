#ifndef OPTICRIB_HAND_H
#define OPTICRIB_HAND_H
#include "cardcollection.h"

class Hand : public CardCollection {
public:
    Hand();
    int count_hand(); // TODO: placeholder for score counting method
    void change_order(int old_ix, int new_ix);
};

#endif //OPTICRIB_HAND_H
