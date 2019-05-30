#include "stack.h"
#include <algorithm>
#include <iostream>

Stack::Stack() {}


int Stack::check_run() {
    // Returns the point value achieved by runs


}

int Stack::check_repeat() {
    // Returns the point value achieved by repeat cards
    // This is a brute force method...
    int j = 3;
    while (j < cards.size()) {
        int vals[j];

        for (int i = 0; i < j; i++ ) {
            vals[i] = cards[i].get_value();
        }

        std::cout << j << std::endl;
        std::sort(vals, vals + j);
        j+=1;

    }

}

int Stack::check_num(int num) {
    // Returns the point value achieved by 15's and 31's
    if (get_current_value() == num) {
        return 2;
    } else {
        return 0;
    }

}


int Stack::get_current_value() {
    int val = 0;
    for (int i = 0; i < cards.size(); i++) {
        val+= cards[i].get_crib_value();
    }

    return val;
}

int Stack::check_score(Player &player) {
    // Checks all point conditions
    int add_score = 0;

    add_score += check_num(15);
    add_score += check_num(31);

    add_score += check_repeat();
    add_score += check_run();

    return add_score;
}
