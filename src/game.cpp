#include "game.h"
#include "SDL.h"
#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height), engine(dev()),
      random_color(0, 3), // STEP 1.2
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();

    renderer.Render(snake, food, _foodColor,
                    _cannibalFood); // STEP 1.3 + STEP 2.2

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
      // STEP 2.4
      snake._lifeDeadBody++; // Age the dead body
    }

    // STEP 2.4
    if (snake._lifeDeadBody > 10) {
      snake._deadBody.clear();
    };

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;

    // STEP 1.3
    snake._snakeColor = _foodColor;    // The snake takes on the food Color
    _foodColor = random_color(engine); // A new color is picked for the food
    PlaceFood();

    // STEP 2.1
    if ((GetScore() + 1) % 15 == 0) { // Is it time for some cannibalisme? 
      _cannibalFood = true;
    } else if (GetScore() % 15 == 0) {
      snake._cannibal = true;
      _cannibalFood = false;
    } else {
      snake._cannibal = false;
      _cannibalFood = false;
    }

    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.01;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }