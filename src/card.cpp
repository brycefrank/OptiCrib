#include "card.h"
#include <string>
#include <iostream>

Card::Card(){}

Card::Card(int v, std::string s) {
    value = v;
    suit = s;
}

int Card::get_value() {
    return value;
}

int Card::get_crib_value() {
    // In cribbage, face cards are worth 10
    if (value >= 10) {
        return 10;
    } else {
        return value;
    }

}

std::string Card::get_suit() {
    return suit;
}


void Card::display() {
    std::string value_str = std::to_string(get_value());
    std::cout << get_suit() << "--" << value_str << std::endl;
}