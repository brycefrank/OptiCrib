#ifndef OPTICRIB_CARD_H
#define OPTICRIB_CARD_H
#include <string>

class Card {
private:
    const char * suit;
    const char * psuit;
    const char * suit_symbol;
    const char * value_char;
    int value;
    const char * value_to_char();
public:
    Card();
    Card(int v, const char * s);
    char * get_char();
    int get_value();
    int get_crib_value();
    std::string get_suit();
    void display_center(int posy);

};

#endif //OPTICRIB_CARD_H
