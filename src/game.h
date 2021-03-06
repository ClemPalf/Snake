#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <random>

class Game {
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  // STEP 2.1
  bool _cannibalFood; // Is the food filled with the cannibal power??
  // STEP 1.1
  int _foodColor;

private:
  Snake snake;
  SDL_Point food;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  // STEP 1.2
  std::uniform_int_distribution<int> random_color;
  int score{0};
  void PlaceFood();
  void Update();
};

#endif