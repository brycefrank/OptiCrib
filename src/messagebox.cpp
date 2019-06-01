#include "messagebox.h"
#include <iostream>

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
