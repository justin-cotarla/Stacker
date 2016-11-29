#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include "Point.h"

class Grid;

class Block{
public:

	Block(Point p, Grid *g, SDL_Texture *block_texture);
	~Block();

	//Sets block position
	void setPosition(Point p);

	//Returns position
	Point getPosition() const;

	//Renders block on given surface
	void render(SDL_Renderer *gRenderer);

	//Places block is in valid position (return true); deletes itself otherwise (false)
	bool stop();

private:


	Point position;
	SDL_Texture *block_texture;
	Grid *grid;
	SDL_Rect blockBounds;

};

#endif