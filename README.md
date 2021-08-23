# Personalized Snake Game


<p align="center">
  <img src="https://github.com/ClemPalf/Snake/blob/main/Illustration_1.png?raw=true"/>
  <img src="https://github.com/ClemPalf/Snake/blob/main/Illustration_2.png?raw=true"/>
  
</p>

## Description
I built this little snake game on top of a udacity [repo](https://github.com/udacity/CppND-Capstone-Snake-Game), to which I added 2 features:                      
1) **Snake/Cameleon!
The food is assigned a random color every time it is instantiated (4 different colors). When the snake eats the food, it takes on the food color.**                                 
2) **Cannibal! Every 15 levels, the food gives the cannibal power. Until eating the next food, the snake has the capacity to eat himself ONCE. The body is then split in 2. The dead body will take 10 seconds to disappear. If the snake hits it, its over.
Ps: The cannibal food is purple.**  

Have fun!!


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
