#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
  case Direction::kUp:
    head_y -= speed;
    break;

  case Direction::kDown:
    head_y += speed;
    break;

  case Direction::kLeft:
    head_x -= speed;
    break;

  case Direction::kRight:
    head_x += speed;
    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell,
                       SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // STEP 2.5
  // Check if the snake has died from the deadBody.
  for (auto const &item : _deadBody) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
      std::cout << "GAME OVER!\n";
    }
  }

  // Check if the snake has died.
  int i = 1; // This variable determine the position where the snake hit itself
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      // STEP 2.3
      if (_cannibal == true) {
        for (int _ = 0; _ < i; _++) {
          _deadBody.insert(_deadBody.begin(),
                           body[0]); // From the end of the snake queue, to the
                                     // impact point, everything is dead
          body.erase(body.begin());  // The dead part disappear of the body
        }
        _deadBody.erase(_deadBody.begin());
        _cannibal = false;  // The snake loses its power
        size = body.size(); // Update size
        // STEP 2.4
        _lifeDeadBody = 0; // The dead body started its decomposition
      } else {
        alive = false;
        std::cout << "GAME OVER!\n";
      }
    }
    i++;
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}