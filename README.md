# Stacker
This is a clone of the popular Stacker game which is found in malls and arcades.

## Compiling
Stacker uses [SDL2](https://www.libsdl.org/) and [SDL2_Image](https://www.libsdl.org/projects/SDL_image/).


### Linux
1. Install SDL2 and SDL2_Image development libraries: `sudo apt-get install libsdl2-dev libsdl2-image-dev`
2. Compile with g++: ``g++ *.cpp -o stacker `sdl2-config --cflags --libs` -lSDL2_image``

## Instructions
To play the game, press spacebar to stop the moving block(s) on a row. Only stacked blocks remain.
The game is won when the stack reaches the top of the grid.

