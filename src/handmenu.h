#ifndef OPTICRIB_HANDMENU_H
#define OPTICRIB_HANDMENU_H
#include <ncurses.h>
#include <array>
#include <vector>
#include "hand.h"

class HandMenu {
private:
    WINDOW * win;
public:
    HandMenu(int player_num);
    std::array<int, 2> display_discard_menu(Hand& hand);
    void display_hand(Hand& hand, int player_num, bool hide);
    void display_hand2(Hand& hand, int highlight);
    bool validate_selection(std::array<int, 2> selection);
};

#endif //OPTICRIB_HANDMENU_H
