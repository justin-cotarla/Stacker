#ifndef GRID_H
#define GRID_H

#include <vector>
using namespace std;

struct Point;
class Block;
struct SDL_Texture;
struct SDL_Renderer;

class Grid{

public:

	Grid(int width, int height, SDL_Texture *grid_texture);
	~Grid();

	//Checks if cell exists in grid
	bool is_cell_valid(Point &p);

	//Changes the value of an existing cell
	void set_cell(Point &p, Block *b);

	//Empties grid for given row
	void clear_row(int row);

	//Returns block for given cell
	Block* get_cell(Point &p);

	//Returns width of grid in cells
	int get_width() const;

	//Returns height of grid in cells
	int get_height() const;

	//Resets grid
	void reset();

	//Renders grid on given surface
	void render(SDL_Renderer *gRenderer);

private:

	int width;
	int height;

	vector<vector<Block*>> block_grid;

	SDL_Texture* grid_texture;
};





#endif