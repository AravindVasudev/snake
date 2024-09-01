#include "snake.h"

#include "color.h"

void Snake::draw(WINDOW* window) {
  wattron(window, COLOR_PAIR(Color::SnakeC));
  mvwprintw(window, position.X, position.Y, "[]");
  wattroff(window, COLOR_PAIR(Color::SnakeC));
}