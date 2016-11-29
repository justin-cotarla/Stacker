#include "Block.h"
#include "Grid.h"
#include <SDL_image.h>
#include "Constants.h"

Block::Block(Point p, Grid *g, SDL_Texture *block_texture):
	  position(p), grid(g), block_texture(block_texture){

	grid->set_cell(p, this);

	blockBounds.w = constants::BLOCK_PIXEL_SIZE;
	blockBounds.h = constants::BLOCK_PIXEL_SIZE;
}

Block::~Block(){
	grid = nullptr;
}

void Block::setPosition(Point p){
	position = p;
	grid->set_cell(position, this);
}

Point Block::getPosition() const{
	return position;
}

bool Block::stop(){
	if(grid->is_cell_valid(position) && (position.y == 0 || grid->get_cell(position.bottomPoint()) != nullptr)){
		grid->set_cell(position, this);
		return true;
	}else{
		grid->set_cell(position, nullptr);
		delete this;
		return false;
	}
}

void Block::render(SDL_Renderer *gRenderer){
	blockBounds.x = (1 + position.x * (blockBounds.w + 1));
	blockBounds.y = constants::GRID_PIXEL_HEIGHT - 1 - blockBounds.h  - (position.y * (blockBounds.h + 1));
	SDL_RenderCopy(gRenderer, block_texture, NULL, &blockBounds);
}
