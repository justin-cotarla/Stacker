#include "BlockGroup.h"
#include "Grid.h"
#include "Stacker.h"
#include <SDL.h>
#include "Block.h"
#include "Utility.h"

BlockGroup::BlockGroup(Grid *g, Stacker *s, Point position, int block_num):
 grid(g), stacker(*s), position(position), block_num(block_num){
	s = nullptr;
	for(int i = 0; i < block_num; i++){
		blocks.push_back(new Block(Point(position.x + i, position.y), grid, stacker.get_texture(Stacker::BLOCK_TEXTURE)));
	}

	move_dir = rand()%2;
	dir_changed = false;

	move();
}

 BlockGroup::~BlockGroup(){
	 for(int i = 0; i < block_num; i++){
		 blocks[i] = nullptr;
	 }
	 grid = nullptr;
 }

 void BlockGroup::move(){

	 if(move_dir == LEFT){

		 if(dir_changed || grid->is_cell_valid(Point(blocks[block_num-1]->getPosition().x - 1, blocks[block_num-1]->getPosition().y))){

			 for(int i = 0; i < block_num; i++){

				 Point current_position(blocks[i]->getPosition());
				 blocks[i]->setPosition(Point(current_position.x - 1, current_position.y));

			 }

			 dir_changed = false;

		 }else{

			 move_dir = RIGHT;
			 dir_changed = true;
			 move();

		 }

	 }else{

		  if(dir_changed || grid->is_cell_valid(Point(blocks[0]->getPosition().x + 1, blocks[0]->getPosition().y))){

			 for(int i = 0; i < block_num; i++){

				 Point current_position = blocks[i]->getPosition();
				 blocks[i]->setPosition(Point(current_position.x + 1, current_position.y));

			 }
			 dir_changed = false;
		 }else{

			 move_dir = LEFT;
			 dir_changed = true;
			 move();

		 }
	 }
 }

 void BlockGroup::stop(){

	 int new_block_num = block_num;

	 for(int i = 0; i < block_num; i++){

		if(blocks[i]->stop() == false){

			new_block_num--;

		}

		blocks[i] = nullptr;
	 }

	 if(new_block_num == 0){
		 stacker.lose();
	 }else{
 		stacker.level_up(new_block_num);
	 }

 }

