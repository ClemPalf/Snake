#include "renderer.h"
#include "game.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width), screen_height(screen_height),
      grid_width(grid_width), grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food,
                      int const &foodColor,
                      bool const &cannibalFood) { // STEP 1.3 + STEP 2.2
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  // STEP 1.4 + STEP 2.2
  if (cannibalFood == true) {
    SDL_SetRenderDrawColor(sdl_renderer, 159, 43, 104, 0);
  } // Purple (cannibal color)
  else {
    if (foodColor == 0) {
      SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 0, 0);
    } // Yellow
    if (foodColor == 1) {
      SDL_SetRenderDrawColor(sdl_renderer, 0, 255, 0, 0);
    } // Green
    if (foodColor == 2) {
      SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 255, 0);
    } // Blue
    if (foodColor == 3) {
      SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 0);
    } // White
  }

  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  if (snake._cannibal == true) {
    SDL_SetRenderDrawColor(sdl_renderer, 159, 43, 104, 0);
  } // Purple (cannibal color)
  else {
    if (snake._snakeColor == 0) {
      SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 0, 0);
    } // Yellow
    if (snake._snakeColor == 1) {
      SDL_SetRenderDrawColor(sdl_renderer, 0, 255, 0, 0);
    } // Green
    if (snake._snakeColor == 2) {
      SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 255, 0);
    } // Blue
    if (snake._snakeColor == 3) {
      SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 0);
    } // White
  }

  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // STEP 2.4
  // Render snake's deadBody
  if (snake._lifeDeadBody < 4) {
    SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0xFF);
  } else if (snake._lifeDeadBody < 7) {
    SDL_SetRenderDrawColor(sdl_renderer, 150, 0, 0, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 50, 0, 0, 0xFF);
  }
  for (SDL_Point const &point : snake._deadBody) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) +
                    " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
