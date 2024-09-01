#include "pellet.h"

#include <cstdlib>

#include "color.h"

void Pellet::move() {
  position.X = (rand() % WIDTH) + 1;
  position.Y = (rand() % HEIGHT) + 1;
}

void Pellet::draw(WINDOW* window) {
  wattron(window, COLOR_PAIR(Color::SnakeC));
  mvwprintw(window, position.Y, position.X, "X");
  wattroff(window, COLOR_PAIR(Color::SnakeC));
}