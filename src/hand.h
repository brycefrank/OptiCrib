#ifndef OPTICRIB_HAND_H
#define OPTICRIB_HAND_H
#include "cardcollection.h"

class Hand : public CardCollection {
private:
    void combinationUtil(std::vector<int> arr, int n, int r,
                     int index, std::vector<int>data, int i, std::vector<std::vector <int>> &container);
public:
    Hand();
    int count_fifteens(Card stack_card);
    int count_hand(Card stack_card); // TODO: placeholder for score counting method
    void change_order(int old_ix, int new_ix);
};

#endif //OPTICRIB_HAND_H
