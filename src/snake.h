#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"
#include <vector>

class Snake {
public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width), grid_height(grid_height),
        head_x(grid_width / 2), head_y(grid_height / 2) {}

  void Update();
  void GrowBody();
  bool SnakeCell(int x, int y);
  Direction direction = Direction::kUp;
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
  // STEP 2.4
  int _lifeDeadBody; // _deadBody lifetime in seconds;
  // STEP 2.1
  bool _cannibal; // Does the snake has the cannibal power?
  std::vector<SDL_Point> _deadBody; // Rest of the snake body once he ate himself
  // STEP 1.1
  int _snakeColor;

private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif