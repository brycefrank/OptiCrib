#include "Card.h"
#include <string>

Card::Card(){}

Card::Card(int v, std::string s) {
    value = v;
    suit = s;
}

int Card::getvalue() {
    return value;
}

std::string Card::getsuit() {
    return suit;
}
