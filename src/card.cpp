#include "card.h"
#include <string>
#include <iostream>

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


void Card::display() {
    std::string value_str = std::to_string(getvalue());
    std::cout << getsuit() << "--" << value_str << std::endl;
}