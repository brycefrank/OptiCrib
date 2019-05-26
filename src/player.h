#ifndef OPTICRIB_PLAYER_H
#define OPTICRIB_PLAYER_H
#include "card.h"
#include "hand.h"
#include <vector>

class Player {
private:
    std::string role;
public:
    Player();
    Hand hand;

    void setrole(std::string r);
    std::string getrole();


    void discard_phase(Hand crib);
    void random_discard(Hand crib);
};

#endif //OPTICRIB_PLAYER_H
