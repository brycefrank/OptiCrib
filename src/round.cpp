#include "round.h"
#include <iostream>


Round::Round() {
    starting_sequence();
    preplay();
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

void Round::preplay() {
    stage = "preplay";

    // Deal to each player
    deal();

    // Display hand to user
    player1.display_hand();

    // Ask user to discard into crib
    Card crib[4];
    Card* p1_discard = player1.discard_phase();

    // Remove two random cards from AI
    Card* p2_discard = player1.random_discard();

    for (int i = 0; i < 4; i+=2) {
        crib[i] = p1_discard[i];
        crib[i+1] = p2_discard[i];
    }
}

void Round::play() {
    stage = "play";




}

void Round::deal() {
    int hand_size = 6;

    Player* pone;
    Player* dealer;

    if (player1.getrole() == "Pone") {
        std::cout << "You are pone!" << std::endl;
        pone = &player1;
        dealer = &player2;
    } else {
        std::cout << "You are dealer!" << std::endl;
        pone = &player2;
        dealer = &player1;
    }

    for (int i = 0; i < hand_size; i++) {
        pone->hand.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
        dealer->hand.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
    }

}

std::string Round::getstage() {
    return stage;
}
