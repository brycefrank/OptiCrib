#ifndef OPTICRIB_CARD_H
#define OPTICRIB_CARD_H
#include <string>

class Card {
private:
    std::string suit;
    int value;
public:
    Card();
    Card(int v, std::string s);
    int get_value();
    int get_crib_value();
    std::string get_suit();
    void display();
};

#endif //OPTICRIB_CARD_H
