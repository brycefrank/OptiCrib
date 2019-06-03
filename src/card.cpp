#include "card.h"
#include <string>
#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <cstring>

Card::Card(){}

Card::Card(int v, const char * s) {
    value = v;
    suit = s;


    switch(value) {
        case  1: value_char = "A";
        case 11: value_char = "J";
        case 12: value_char = "Q";
        case 13: value_char = "K";
        default: value_char = value_to_char();
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

// TODO refactor these...
// TODO this should involve value_char, not value
char * Card::get_char() {
    // Gets the char array for a pretty print version of the card
    std::string str_val = std::to_string(value);
    std::string temp = str_val + "--" + psuit;
    char * tab2 = new char [temp.length()+1];
    strcpy(tab2, temp.c_str());
    return tab2;
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
