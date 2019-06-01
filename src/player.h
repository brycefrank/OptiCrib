#ifndef OPTICRIB_PLAYER_H
#define OPTICRIB_PLAYER_H
#include "card.h"
#include "hand.h"
#include <vector>

class Player {
private:
    std::string role;
    int player_num;
public:
    Player(int num);
    Hand hand;

    //int get_num();

    void setrole(std::string r);
    std::string getrole();


    void discard_phase(Hand crib);
    void random_discard(Hand crib);
    void display_hand_window();
};

#endif //OPTICRIB_PLAYER_H
