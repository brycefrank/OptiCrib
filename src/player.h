#ifndef OPTICRIB_PLAYER_H
#define OPTICRIB_PLAYER_H
#include "card.h"
#include "hand.h"
#include <array>
#include <ncurses.h>

class Player {
private:
    std::string role;
    int player_num;
    WINDOW * win;

public:
    Player(int num);
    Hand hand;

    //int get_num();

    void setrole(std::string r);
    std::string getrole();


    std::array<int, 2> discard_phase();
    void random_discard(Hand crib);
    void display_hand_window();
    void display_hand(bool hide=true);
};

#endif //OPTICRIB_PLAYER_H
