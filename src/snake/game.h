#pragma once

#include <curses.h>

#include "pellet.h"
#include "snake.h"

class Game {
private:
  WINDOW *window; // Game window.
  Snake snake;
  Pellet pellet;
  int score{};

  void drawScore();
  void drawGameOver();

public:
  Game();
  ~Game();
  void run();
};