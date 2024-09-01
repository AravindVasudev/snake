#pragma once

#include <curses.h>

#include "constants.h"
#include "point.h"

class Snake {
 private:
  Point position{SNAKE_X, SNAKE_Y};

 public:
  void draw(WINDOW* window);
};