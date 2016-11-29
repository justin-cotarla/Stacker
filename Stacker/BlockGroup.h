#ifndef BLOCK_GROUP_H
#define BLOCK_GROUP_H

#include "Point.h"
#include <vector>

class Grid;
class Stacker;
class Block;

class BlockGroup{

public:

	BlockGroup(Grid *g, Stacker *s, Point position, int block_num);
	~BlockGroup();

	//Moves entire group in specified direction, changing dir if edge of grid is reached
	void move();

	
	//Stops all blocks in group
	void stop();

private:

	static const int LEFT = 0;
	static const int RIGHT = 1;

	Stacker &stacker;
	Grid *grid;
	Point position;
	std::vector<Block*> blocks;

	int move_dir;
	int wait_time;
	int block_num;
	bool dir_changed;

	bool is_moving;



};

#endif