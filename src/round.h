#ifndef OPTICRIB_ROUND_H
#define OPTICRIB_ROUND_H
#include "player.h"
#include "deck.h"
#include "stack.h"
#include "hand.h"
#include "messagebox.h"
#include <string>
#include <ncurses.h>

class Round {
private:
    Player player1 = Player(1);
    Player player2 = Player(2);
    std::string stage; // The current "stage" of the round
    Deck deck;
    Stack stack;
    Hand crib; // The crib is really just another hand...
    MessageBox message_box;

    void starting_sequence();
    void deal();
    void preplay(); // The stage where users discard to crib
    void play(); // The play stage
    void play_round(); // The individual "round" of a play
    void show(); // The show stage


public:
    Round();
    std::string getstage();

};

#endif //OPTICRIB_ROUND_H
