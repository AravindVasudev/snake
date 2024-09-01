#include "snake.h"

#include "color.h"

void Snake::input(const char& input) {
  switch (input) {
    case 'w':
      velocity.X = 0;
      velocity.Y = -1;
      break;
    case 's':
      velocity.X = 0;
      velocity.Y = 1;
      break;
    case 'a':
      velocity.X = -1;
      velocity.Y = 0;
      break;
    case 'd':
      velocity.X = 1;
      velocity.Y = 0;
      break;
  }
}

MoveState Snake::move(const Pellet& pellet) {
  // Move the snake.
  position.X += velocity.X;
  position.Y += velocity.Y;

  // Bound check.
  if (position.X <= 0 || position.X >= WIDTH || position.Y <= 0 ||
      position.Y >= HEIGHT - 2) {
    return MoveState::DEAD;
  }

  // Snake ate the pellet!
  if (Point::doesOverlap(position, pellet.position)) {
    return MoveState::EAT;
  }

  return MoveState::NOOP;
}

void Snake::draw(WINDOW* window) {
  wattron(window, COLOR_PAIR(Color::SnakeC));
  mvwprintw(window, position.Y, position.X, "🐍");
  wattroff(window, COLOR_PAIR(Color::SnakeC));
}