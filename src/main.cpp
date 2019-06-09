#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "controller.h"
#include "player.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    Controller c;
    c.start();
    int g = getch();
    endwin();
	return 0;
}
