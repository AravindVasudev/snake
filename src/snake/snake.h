#pragma once

#include <curses.h>

#include "constants.h"
#include "point.h"
#include "pellet.h"

// Possible outcomes of a move.
enum MoveState {
  NOOP = 1,
  DEAD,
  EAT,
};

class Snake {
 private:
  Point position{SNAKE_X, SNAKE_Y};
  Point velocity{-1, 0};

 public:
  void draw(WINDOW* window);
  void input(const char& input);
  MoveState move(const Pellet& pellet);
};