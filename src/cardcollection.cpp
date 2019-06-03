#include "cardcollection.h"
#include <iostream>


CardCollection::CardCollection(){}

void CardCollection::add_card(Card card) {
    cards.push_back(card);
}

void CardCollection::transfer_card(int ix, CardCollection& target_col) {
    Card transfer = cards.at(ix);
    target_col.add_card(transfer);
    cards.erase(cards.begin() + ix);
}

void CardCollection::sort(){
}

//void CardCollection::display() {
//    for (int i = 0; i < cards.size(); i++) {
//        cards.at(i).display();
//    }
//}
