#include "round.h"
#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>
#include <algorithm>
#include <array>

Round::Round() {
    deck.display_term();
    message_box.display();
    starting_sequence();
    preplay();
    play();
}

void Round::starting_sequence() {
    stage = "start";
    deck.shuffle();

    // by default player1 is the user, player2 is the computer
    // ask player1 to draw a card
    int draw_int = message_box.get_deck_draw();
    deck.transfer_card(draw_int, player1.hand);
    player1.display_hand();

    int ai_draw = rand() % 50;
    deck.transfer_card(ai_draw, player2.hand);
    player2.display_hand();

    // TODO handle a draw
    if (player2.hand.cards.at(0).get_value() < player1.hand.cards.at(0).get_value()) {
        message_box.new_message("You are pone!");
        player1.setrole("Pone");
        player2.setrole("Dealer");
    } else {
        message_box.new_message("You are dealer!");
        player1.setrole("Dealer");
        player2.setrole("Pone");
    }

    getch();

    // Return cards back to the deck, shuffle
    player1.hand.transfer_card(0, deck);
    player2.hand.transfer_card(0, deck);
    deck.shuffle();
}

void Round::preplay() {
    stage = "preplay";

    // Deal to each player
    deal();

    // Display hand to user
    player1.display_hand();
    player2.display_hand(true);

    // Ask user to discard into crib
    std::vector<int> selected = player1.discard_phase(2);
    std::sort(selected.begin(), selected.end());

    for (size_t i = selected.size(); i--;) {
        message_box.new_message(player1.hand.cards[selected[i]].get_char());
        player1.hand.transfer_card(selected[i], crib);
    }

    player2.random_discard(crib);

    player1.display_hand();
    player2.display_hand(true);
}

void Round::play_round() {
    // A play round is an individual "volley" of plays, to ~31 points
    bool end_round = false;
    Stack stack;

    while (!end_round) {
        int card_id = player1.discard_phase(1)[0];
        stack.display(player1.hand.cards[card_id]);
        player1.hand.transfer_card(card_id, stack);
        stack.check_score(player1);

        int opp_id = 0;
        stack.display(player2.hand.cards[opp_id]);
        player2.hand.transfer_card(opp_id, stack);
        stack.check_score(player2);

        if (stack.get_current_value() > 31) {
            message_box.new_message("break");
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

