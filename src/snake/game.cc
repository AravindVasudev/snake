#include "game.h"

#include <curses.h>
#include <locale.h>
#include <unistd.h>

#include <chrono>

#include "constants.h"

Game::Game() {
  // Init Graphics.
  setlocale(LC_ALL, "");  // Get the terminal outta boomer-mode.
  initscr();
  keypad(stdscr, true);
  curs_set(false);
  timeout(0);
  raw();
  noecho();
}

void Game::run() {
  while (true) {
    char input = getch();
    if (input == 'q') {
      break;
    }

    move(0, 0);
    printw("Hello World!");

    // Handle frame rate.
    usleep(1000000 / FRAME_RATE);
  }
}