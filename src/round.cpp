#include "round.h"
#include <iostream>


Round::Round() {
    starting_sequence();
    play();
}

void Round::starting_sequence() {
    stage = "start";
    deck.shuffle();

    // by default player1 is the user, player2 is the computer
    // ask player1 to draw a card
    int player_draw;
    std::cout << "Enter a number between 1 and 52: ";
    std::cin >> player_draw;
    player_draw = player_draw - 1;
    Card player_card = deck.drawcard(player_draw);

    int ai_draw = rand() % 50;
    Card ai_card = deck.drawcard(ai_draw);

    if (ai_card.getvalue() < player_card.getvalue()) {
        player1.setrole("Pone");
        player2.setrole("Dealer");
    } else {
        player1.setrole("Dealer");
        player2.setrole("Pone");
    }

    // Return cards back to the deck, shuffle
    deck.cards.push_back(ai_card);
    deck.cards.push_back(player_card);
    deck.shuffle();
}

void Round::play() {
    stage = "play";

    // Deal to each player
    deal();

    // Display hand to user...
    player1.display_hand();


}

void Round::deal() {
    int hand_size = 6;

    Player* pone;
    Player* dealer;

    if (player1.getrole() == "Pone") {
        pone = &player1;
        dealer = &player2;
    } else {
        pone = &player2;
        dealer = &player1;
    }


    for (int i = 0; i < hand_size * 2; i+=2) {
        pone->hand.push_back(deck.cards[i]);
        dealer->hand.push_back(deck.cards[i+1]);
    }

}

std::string Round::getstage() {
    return stage;
}
