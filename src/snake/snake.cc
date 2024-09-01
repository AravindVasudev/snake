#include "snake.h"

#include "color.h"

void Snake::input(const char& input) {
  switch (input) {
    case 'w':
      velocity.X = -1;
      velocity.Y = 0;
      break;
    case 's':
      velocity.X = 1;
      velocity.Y = 0;
      break;
    case 'a':
      velocity.X = 0;
      velocity.Y = -1;
      break;
    case 'd':
      velocity.X = 0;
      velocity.Y = 1;
      break;
  }
}

MoveState Snake::move() {
  // Move the snake.
  position.X += velocity.X;
  position.Y += velocity.Y;

  // Bound check.
  if (position.X <= 0 || position.X >= WIDTH || position.Y <= 0 ||
      position.Y >= HEIGHT) {
    return MoveState::DEAD;
  }

  return MoveState::NOOP;
}

void Snake::draw(WINDOW* window) {
  wattron(window, COLOR_PAIR(Color::SnakeC));
  mvwprintw(window, position.X, position.Y, "[]");
  wattroff(window, COLOR_PAIR(Color::SnakeC));
}