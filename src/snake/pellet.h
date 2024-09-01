#pragma once

#include <curses.h>

#include "constants.h"
#include "point.h"

class Pellet {
 public:
  Point position{};

  void move();
  void draw(WINDOW* window);
};