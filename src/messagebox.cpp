#include "messagebox.h"
#include <iostream>
#include <cstring>

MessageBox::MessageBox() {
    height = 8;
    width = 50;
    pos_y = 1;
    pos_x = 35;
}

void MessageBox::display() {
    message_box = newwin(height, width, pos_y, pos_x);
    box(message_box, 0, 0);
    wprintw(message_box, "Message Box");
    wrefresh(message_box);
}

void MessageBox::cycle_messages() {
    wclear(message_box);
    box(message_box, 0, 0);
    int pos = 0;
    for (int i = messages.size()-1; i >= 0; i--){
        mvwprintw(message_box, 1+pos, 1, messages[i]);
        pos += 1;
    }
    wrefresh(message_box);
}

void MessageBox::new_message(const char * message) {
    messages.push_back(message);
    cycle_messages();
}

// TODO this
bool MessageBox::validate_draw() {
    // Checks if draw can be converted to an integer between 1 and 52
}

int MessageBox::get_deck_draw() {
    new_message("Enter a number between 1 and 52: ");
    char str[2];
    move(pos_y + 1, pos_x + strlen(messages.at(0)) + 1);
    echo();
    curs_set(1);
    getstr(str);
    curs_set(0);
    noecho();
    int draw_int = std::stoi(str);
    return draw_int;
}
