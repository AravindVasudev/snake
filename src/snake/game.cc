#include "game.h"

#include <locale.h>
#include <unistd.h>

#include <chrono>

#include "constants.h"

Game::Game() {
  // Init graphics.
  setlocale(LC_ALL, "");  // Get the terminal outta boomer-mode.
  initscr();
  keypad(stdscr, true);
  curs_set(false);
  timeout(0);
  raw();
  noecho();

  // Init game window.
  window = newwin(HEIGHT, WIDTH, 0, 0);
  refresh();
  box(window, 0, 0);
}

void Game::run() {
  while (true) {
    char input = getch();
    if (input == 'q') {
      break;
    }

    mvwprintw(window, 0, 1, "Hello World!");
    wrefresh(window);

    // Handle frame rate.
    usleep(1000000 / FRAME_RATE);
  }
}