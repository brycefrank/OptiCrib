#include "hand.h"
#include <algorithm>

Hand::Hand(){}

int Hand::count_hand() {}

void Hand::change_order(int old_ix, int new_ix) {
    std::iter_swap(cards.begin() + old_ix, cards.begin() + new_ix);
}

