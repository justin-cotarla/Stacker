#include "Grid.h"
#include "Point.h"
#include "Block.h"
#include <SDL.h>
#include <SDL_image.h>


Grid::Grid(int width, int height, SDL_Texture *grid_texture):
 width(width), height(height), grid_texture(grid_texture){

	for(int i = 0; i < width; i++){
		vector<Block*> v;
		for(int j = 0; j < height; j++){
			Block* b = nullptr;
			v.push_back(b);
		}
		block_grid.push_back(v);
	}


}

Grid::~Grid(){
	reset();
}

bool Grid::is_cell_valid(Point& p){
	if(p.x >= 0 && p.x < width){
		return true;
	}else{
		return false;
	}
}

void Grid::clear_row(int row){
	for(int i = 0; i < width; i++){
		set_cell(Point(i, row), nullptr);
	}
}

void Grid::set_cell(Point &p, Block *b){
	if(is_cell_valid(p)){
		block_grid[p.x][p.y] = b;
	}
}

Block* Grid::get_cell(Point &p){
	return block_grid[p.x][p.y];
}

int Grid::get_width() const{
	return width;
}

int Grid::get_height() const{
	return height;
}

void Grid::reset(){
		for(int j = 0; j < height; j++){
			clear_row(j);
		}
}

void Grid::render(SDL_Renderer *gRenderer){
	SDL_RenderCopy(gRenderer, grid_texture, NULL, NULL);
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			if(block_grid[i][j] != nullptr){
				block_grid[i][j]->render(gRenderer);
			}
		}
	}
}
