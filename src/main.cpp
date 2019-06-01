#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "controller.h"

int main() {
    Controller c;
    c.start();

    int g = getch();
    endwin();
	return 0;
}
