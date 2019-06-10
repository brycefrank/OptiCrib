#ifndef OPTICRIB_HANDMENU_H
#define OPTICRIB_HANDMENU_H
#include <ncurses.h>
#include <vector>
#include "hand.h"

class HandMenu {
private:
    WINDOW * win;
public:
    HandMenu(int player_num);
    std::vector<int> get_selection(Hand& hand, int length);
    void display_hand(Hand& hand, int highlight = -1, bool hide=false);
    bool validate_selection(std::vector<int> selection);
};

#endif //OPTICRIB_HANDMENU_H
