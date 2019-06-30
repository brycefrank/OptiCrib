#include "hand.h"
#include <algorithm>
#include <iostream>
#include <array>

Hand::Hand(){}

void Hand::combinationUtil(std::vector<int> arr, int n, int r,
                     int index, std::vector<int>data, int i, std::vector<std::vector <int>> &container)
{

    // Current cobination is ready, print it
    if (index == r) {
        container.push_back(data);
        return;
    }

    if (i < n) {
        data[index] = arr[i];
        combinationUtil(arr, n, r, index + 1, data, i + 1, container);

        // current is excluded, replace it with next (Note that
        // i+1 is passed, but index is not changed)
        combinationUtil(arr, n, r, index, data, i+1, container);
    }
}


int Hand::count_fifteens(Card stack_card) {
    cards.push_back(stack_card);
    for (int r = 2; r < 6; r ++) {
        std::vector<std::vector <int>> container;
        std::vector<int> data(r);
        std::vector<int> arr = {0, 1, 2, 3, 4};

        int n = arr.size();
        combinationUtil(arr, n, r, 0, data, 0, container);

        for (int i = 0; i < container.size(); i++) {
            int sum_total = 0;
            for (int j = 0; j < r; j ++){
                int pos = container[i][j];
                int val = cards.at(pos).get_crib_value();

                sum_total = sum_total + val;

            }


            if (sum_total == 15) {
                pts_15 = pts_15 + 2;
            }

        }

    }

    return pts_15;
}


int Hand::count_hand(Card stack_card) {
    count_fifteens(stack_card);

}

void Hand::change_order(int old_ix, int new_ix) {
    std::iter_swap(cards.begin() + old_ix, cards.begin() + new_ix);
}

