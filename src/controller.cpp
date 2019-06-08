#include <iostream>
#include "controller.h"
#include "round.h"

Controller::Controller() {
}



void Controller::start() {
    initscr();
    noecho();
    curs_set(0);
    Round r;
}