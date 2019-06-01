#include "round.h"
#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>


Round::Round() {
    display_interface();
    starting_sequence();
    //preplay();
    //play();
}

void Round::display_interface() {
    initscr();
    noecho();
    curs_set(0);

    deck.display_term();
    player1.display_hand_window();
    player2.display_hand_window();

    message_box.display();
}


void Round::starting_sequence() {
    stage = "start";
    deck.shuffle();

    // by default player1 is the user, player2 is the computer
    // ask player1 to draw a card
    char str[2];
    message_box.new_message("Enter a number between 1 and 52: ");
    curs_set(1);
    wmove(message_box.message_box, 0, 0);
    echo();
    getstr(str);
    curs_set(0);
    noecho();
    int draw_int = std::stoi(str);
    Card player_card = deck.cards[draw_int];

    int ai_draw = rand() % 50;
    Card ai_card = deck.cards[ai_draw];

    if (ai_card.get_value() < player_card.get_value()) {
        message_box.new_message("You are pone!");
        player1.setrole("Pone");
        player2.setrole("Dealer");
    } else {
        message_box.new_message("You are dealer!");
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
    //player1.hand.display();

    // Ask user to discard into crib
    player1.discard_phase(crib);

    // Remove two random cards from AI hand
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
        stack.check_score(player1);

        player2.hand.transfer_card(0, stack);
        stack.check_score(player2);

        // FIXME rough but working for debugging
        int stack_value = stack.get_current_value();
        std::cout << stack_value << std::endl;

        if (stack_value > 31) {
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

