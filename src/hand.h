#ifndef OPTICRIB_HAND_H
#define OPTICRIB_HAND_H
#include "cardcollection.h"

class Hand : public CardCollection {
public:
    Hand();
    int count_hand(); // TODO: placeholder for score counting method
};

#endif //OPTICRIB_HAND_H
