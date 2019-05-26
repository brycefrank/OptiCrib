#include "round.h"
#include <iostream>
#include <vector>


Round::Round() {
    starting_sequence();
    preplay();
    //play();
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
    Card player_card = deck.get_card(player_draw);

    int ai_draw = rand() % 50;
    Card ai_card = deck.get_card(ai_draw);

    if (ai_card.getvalue() < player_card.getvalue()) {
        player1.setrole("Pone");
        player2.setrole("Dealer");
    } else {
        player1.setrole("Dealer");
        player2.setrole("Pone");
    }

    // Return cards back to the deck, shuffle
    deck.add_card(ai_card);
    deck.add_card(player_card);
    deck.shuffle();

}

void Round::preplay() {
    stage = "preplay";

    // Deal to each player
    deal();

    // Display hand to user
    player1.hand.display();

    // Ask user to discard into crib
    player1.discard_phase(crib);

    // Remove two random cards from AI
    player2.random_discard(crib);
}

void Round::play_round() {
    // A play round is an individual "volley" of plays, to ~31 points
    int current_value = 0;
    bool end_round = false;
    Stack stack;

    while (!end_round) {
        int card_id;
        player1.hand.display();
        std::cout << "Play a card: ";
        std::cin >> card_id;
        player1.hand.transfer_card(card_id, stack);


        // FIXME rough but working for debugging
        current_value += stack.get_card(0).getvalue();
        std::cout << current_value << std::endl;

        if (current_value > 31) {
            end_round = true;
        }
    }
}

void Round::play() {
    stage = "play";
    play_round();
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
        deck.transfer_card(i, pone->hand);
        deck.transfer_card(i, dealer->hand);
    }

}

std::string Round::getstage() {
    return stage;
}
