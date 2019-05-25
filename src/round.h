#ifndef OPTICRIB_ROUND_H
#define OPTICRIB_ROUND_H
#include "player.h"
#include "deck.h"
#include <string>

class Round{
private:
    Player player1;
    Player player2;
    std::string stage; // The current "stage" of the round
    Deck deck;

    void starting_sequence();
    void deal();
    void play(); // The play stage
    void show(); // The show stage


public:
    Round();
    std::string getstage();
};

#endif //OPTICRIB_ROUND_H
