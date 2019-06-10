#ifndef OPTICRIB_PLAYER_H
#define OPTICRIB_PLAYER_H
#include "card.h"
#include "hand.h"
#include "handmenu.h"
#include <array>
#include <ncurses.h>

class Player {
private:
    std::string role;
    int player_num;
    HandMenu hand_menu;
public:
    Player(int num);
    Hand hand;

    void setrole(std::string r);
    std::string getrole();


    std::vector<int> discard_phase(int num_discard);
    void random_discard(Hand crib);
    void display_hand(bool hide=true);
};

#endif //OPTICRIB_PLAYER_H
