#include "game.h"

#include <locale.h>
#include <unistd.h>

#include <chrono>

#include "color.h"
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

  // Init Colors.
  start_color();
  init_pair(Color::WindowC, COLOR_BLACK, COLOR_GREEN);
  init_pair(Color::SnakeC, COLOR_BLACK, COLOR_GREEN);

  // Init game window.
  window = newwin(HEIGHT, WIDTH, 0, 0);
  refresh();

  // Style window.
  wbkgd(window, COLOR_PAIR(Color::WindowC));
  box(window, 0, 0);
}

void Game::drawScore() { mvwprintw(window, 0, 2, "Score: %d", score); }

void Game::run() {
  while (true) {
    char input = getch();
    if (input == 'q') {
      break;
    }

    // Draw all objects.
    snake.draw(window);
    drawScore();

    // Refresh frame.
    wrefresh(window);
    usleep(1000000 / FRAME_RATE);
  }
}