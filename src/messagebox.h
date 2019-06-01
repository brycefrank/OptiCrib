#ifndef OPTICRIB_MESSAGEBOX_H
#define OPTICRIB_MESSAGEBOX_H
#include <ncurses.h>
#include <vector>
#include <string>

class MessageBox {
private:
    std::vector<const char *> messages;
    void cycle_messages(); // this will just move old messages down and insert the new message at the top
    int height;
    int width;
    int pos_y;
    int pos_x;
public:
    MessageBox();
    WINDOW* message_box;
    void display();
    void new_message(const char * message);
};

#endif //OPTICRIB_MESSAGEBOX_H
