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
    int getvalue();
    int getcribvalue();
    std::string getsuit();
    void display();
};

#endif //OPTICRIB_CARD_H
