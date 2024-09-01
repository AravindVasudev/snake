#include <curses.h>

#include "snake/game.h"

int main() {
  Game game;
  game.run();

  // Reset timeout and block.
  timeout(-1);
  getch();
  endwin();
}