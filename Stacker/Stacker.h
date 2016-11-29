#ifndef STACKER_H
#define STACKER_H

#include "BlockGroup.h"
#include <SDL.h>


class Grid;
class Menu;

class Stacker{

public:

	static const int BLOCK_TEXTURE = 0;
	static const int GRID_TEXTURE = 1;

	Stacker();
	~Stacker();


	//Restarts Stacker
	void restart();

	//Loses game
	void lose();

	//Increments level
	void level_up(int block_num);

	//Returns surface
	SDL_Texture* get_texture(int ID);

private:

	Menu* menu;
	Grid* grid;
	BlockGroup* current_group;

	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Texture* gTexture;

	SDL_Texture* grid_texture;
	SDL_Texture* block_texture;
	SDL_Texture* menu_texture;

	bool quit;
	bool playing;
	SDL_Event e;

	int block_num;
	int current_level;
	int wait_time;

	//Creates a block group
	BlockGroup* create_group();

	//Wins game
	void win();

	//Sets up program
	bool init();

	//Waits between loop cycles
	void wait();

	//Starts game loop
	void run();

	//Shuts down program
	void close();


};

#endif