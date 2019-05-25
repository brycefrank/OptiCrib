#ifndef OPTICRIB_PLAYER_H
#define OPTICRIB_PLAYER_H
#include "card.h"
#include <vector>

class Player {
public:
    Player();

    void setrole(std::string r);
    std::string getrole();

    std::vector<Card> gethand();
    std::vector<Card> hand;

    void display_hand();
    Card* discard_phase();
    Card* random_discard();

private:
    std::string role;
};

#endif //OPTICRIB_PLAYER_H
