#include "hand.h"
#include <algorithm>
#include <iostream>
#include <vector>

Hand::Hand(){}


int Hand::count_hand(Card stack_card) {
    std::vector<int> vals(cards.size() + 1);

    for (int i = 0; i < cards.size(); i++){
        vals[i] = cards[i].get_crib_value();
    }

    int last_ix = vals.size() - 1;
    vals[last_ix] = cards[last_ix].get_crib_value();
    all_combinations(vals, 3);
}

void Hand::change_order(int old_ix, int new_ix) {
    std::iter_swap(cards.begin() + old_ix, cards.begin() + new_ix);
}

