#include "card.h"
#include <string>
#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <cstring>
#include <iostream>

Card::Card(){}

Card::Card(int v, const char * s) {
    value = v;
    suit = s;

    if (value == 1) {
        value_char = "A";
    }
    else if (value == 11) {
        value_char = "J";
    }
    else if (value == 12) {
        value_char = "Q";
    }
    else if (value == 13) {
        value_char = "K";
    } else {
        value_char = value_to_char();
    }


    if (strcmp(suit, "Diamonds") == 0) {
        psuit = "♦️";
    }
    if (strcmp(suit, "Spades") == 0) {
        psuit = "♠️";
    }
    if (strcmp(suit, "Hearts") == 0) {
        psuit =  "♥️";
    }
    if (strcmp(suit, "Clubs") == 0) {
        psuit = "♣️";
    }

}

const char* Card::value_to_char() {
    std::string str_val = std::to_string(value); // int to string
    char * tab2 = new char [str_val.length()+1]; // container string
    strcpy(tab2, str_val.c_str());
    return tab2;
};

char * Card::get_char() {
    // Gets the char array for a pretty print version of the card
    std::string value_str = value_char;
    std::string psuit_str = psuit;
    std::string temp = value_str + "--" + psuit_str;
    char * out = new char [temp.length()+1];
    strcpy(out, temp.c_str());
    return out;
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


void Card::display_center(int posy) {
    // Displays the char string in the center of the table
    // mostly used when player and AI draw a card to start the round
    mvprintw(posy, 14, get_char());
}
