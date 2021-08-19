# Personalized Snake Game


<p align="center">
  <img src="https://github.com/ClemPalf/Snake/blob/main/Illustration_1.png?raw=true"/>
  <img src="https://github.com/ClemPalf/Snake/blob/main/Illustration_2.png?raw=true"/>
  
</p>

## Description
I built this little snake game on top of a udacity [repo](https://github.com/udacity/CppND-Capstone-Snake-Game), to which I added the 2 additional features:                        


1) Snake/Cameleon!
The food is assigned a random color every time it is instantiated (4 different colors). When the snake eats the food, it takes on the food color.
STEP 1.1
-Create 2 new int variables: _foodColor and _snakeColor (respectively within the game and snake classes).

STEP 1.2
-Create a new uniform_int_distribution within the game class.
-Instantiate it with the game constructor.

STEP 1.3
-When the snake eats the food (within Game::Update()), assign _foodColor to _snakeColor, then, assign a random int (0,1,2,3) to foodColor.
-Within Game::Run, pass the _foodColor variable to renderer.Render(). Make the appropriate change in renderer.cpp/.h.
 
STEP 1.4
-When rendering the food and snake (within Renderer::Render(...)), change the color parameters depending of their associated color ints.


2) Cannibal!
Every 15 levels, the food gives the cannibal power. Until eating the next food, the snake has the capacity to eat himself ONCE. The body is then split in 2. The dead body will take 10 seconds to disappear. If the snake hits it, its over.

Ps: The cannibal food is purple.

STEP 2.1
-Within the snake classe, create a bool variable “_cannibal” and a vector of SDL_Points  “_deadBody”.
-Within the game classe, create a bool varaible “_cannibalFood”.
-Within Game::Update, after placing food, check the score.
If it is a number before a product of 10 (9,19,29...) , set “_cannibalFood” to True.
If it is a product of 10, set “_cannibal” to True.
Else, set both to False.

STEP 2.2
-Modify the renderer::Render function so that it accepts the “_cannibalFood” variable.
-Within  renderer::Render, if “_cannibalFood” = True, make the food purple.
If “snake._cannibal” = True, make the snake body purple.

STEP 2.3
-When checking if the head is on the body (within Snake::UpdateBody), if  Cannibal = true:
split the body from where the head is. The body become the part with the head, the rest is assigned to “deadBody”.

STEP 2.4
-Within the snake classe, create a int variable “_lifeDeadBody”.
-When the snake dead body is created, set the value to 0.
-Every second passed, increment the _lifeDeadBody.
-Within the renderer, progressively reduce the intensity of the color (the body is decomposing!)
-Within Game::Run, if the deadBody has been created more than 10 seconds, destroy it.

STEP 2.5
- Within Snake::UpdateBody, check if the head is into the deadBody, if it is, it’s over!


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
