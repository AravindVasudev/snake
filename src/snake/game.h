#pragma once

#include <curses.h>

class Game {
 private:
  WINDOW* window;  // Game window.

 public:
  Game();
  void run();
};