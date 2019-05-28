#ifndef OPTICRIB_STACK_H
#define OPTICRIB_STACK_H
#include "cardcollection.h"
#include "player.h"

class Stack : public CardCollection {
private:
    int check_run();
    int check_repeat();
    int check_num(int num);

public:
    Stack();
    int get_current_value();
    int check_score(Player& player);
};

#endif //OPTICRIB_STACK_H
