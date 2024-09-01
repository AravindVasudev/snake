#include "snake.h"

#include <algorithm>
#include <ranges>

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
  Point newPosition{head.X + velocity.X, head.Y + velocity.Y};

  // Bound check.
  if (newPosition.X <= 0 || newPosition.X >= WIDTH || newPosition.Y <= 0 ||
      newPosition.Y >= HEIGHT) {
    return MoveState::DEAD;
  }

  // Move the body.
  Point old = head;
  for (auto& t : tail) {
    std::swap(t, old);
  }

  head = newPosition;

  // Snake ate the pellet!
  if (Point::doesOverlap(head, pellet.position)) {
    tail.push_back(Point{pellet.position.X, pellet.position.Y});
    return MoveState::EAT;
  }

  return MoveState::NOOP;
}

void Snake::drawHead(WINDOW* window) {
  switch (velocity.Y) {
    case -1:
      mvwprintw(window, head.Y, head.X, "▲");
      break;
    case 1:
      mvwprintw(window, head.Y, head.X, "▼");
      break;
    default:
      switch (velocity.X) {
        case -1:
          mvwprintw(window, head.Y, head.X, "◀");
          break;
        case 1:
          mvwprintw(window, head.Y, head.X, "▶");
          break;
      }
  }
}

void Snake::draw(WINDOW* window) {
  wattron(window, COLOR_PAIR(Color::SnakeC));
  drawHead(window);
  for (const auto& t : tail) {
    mvwprintw(window, t.Y, t.X, "@");
  }
  wattroff(window, COLOR_PAIR(Color::SnakeC));
}