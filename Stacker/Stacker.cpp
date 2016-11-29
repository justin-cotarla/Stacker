#include "Stacker.h"
#include "Constants.h"
#include "Grid.h"
#include "Menu.h"
#include <SDL_image.h>
#include "Utility.h"

Stacker::Stacker():
 block_num(constants::MAX_BLOCK_NUM){
	init();
	run();
}

Stacker::~Stacker(){
	close();
}

bool Stacker::init(){
	//Initialization flag
    bool success = true;

	//Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize. SDL Error: %s\n", SDL_GetError());
        success = false;
	}else{

		if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			success = false;
		}else{

			//Create window
			gWindow = SDL_CreateWindow("Stacker", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

			if(gWindow == NULL){
				printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
				success = false;

			}else{
				//Create renderer for window
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

				if(gRenderer == NULL){
					printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
					success = false;
				}
            }
		}
    }

	//Game setup

	grid_texture = utility::load_texture("assets/grid.png", gRenderer);
	block_texture = utility::load_texture("assets/block.png", gRenderer);
	menu_texture = utility::load_texture("assets/menu.png", gRenderer);

	wait_time = 200;
	playing= true;
	quit = false;
	current_level = 0;
	grid = new Grid(constants::GRID_POINT_WIDTH, constants::GRID_POINT_HEIGHT, grid_texture);
	menu = new Menu(menu_texture);
	current_group = create_group();

	return success;
}

void Stacker::run(){
	while(!quit){

		while(SDL_PollEvent(&e) != 0){

			if(e.type == SDL_QUIT){

				quit = true;

			}else if(e.type == SDL_KEYDOWN){

				switch(e.key.keysym.sym){

				case SDLK_SPACE:
					if(playing){
						current_group->stop();
					}else{
						restart();
					}
					break;

				case SDLK_UP:

					break;
				case SDLK_DOWN:

					break;
				}
			}
		}

	//Update
	if(playing){
		grid->clear_row(current_level);
		current_group->move();
	}

	//Render
	SDL_RenderClear(gRenderer);
	grid->render(gRenderer);

	SDL_RenderPresent(gRenderer);

	//Wait
	wait();
	}
}

void Stacker::close(){
	delete current_group;
	current_group = nullptr;

	delete grid;
	grid = nullptr;

	delete menu;
	menu = nullptr;

	SDL_DestroyTexture(menu_texture);
	menu_texture = nullptr;

	SDL_DestroyTexture(grid_texture);
	grid_texture = nullptr;

	SDL_DestroyTexture(block_texture);
	block_texture = nullptr;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    SDL_Quit();
}

void Stacker::wait(){
	if(playing){
		SDL_Delay(wait_time);
	}
 }

void Stacker::lose(){
	playing = false;
	menu->set_game_state(Menu::LOSE);
	menu->set_visible(true);
}

void Stacker::level_up(int block_num){

	current_level++;
	wait_time *= 0.89;


	switch(current_level){
	case 3:
		if(block_num == constants::MAX_BLOCK_NUM){
			block_num--;
		}
		break;
	case 9:
		if(block_num == constants::MAX_BLOCK_NUM - 1){
			block_num--;
		}
		break;
	}

	if(current_level < constants::GRID_POINT_HEIGHT){
		this->block_num = block_num;
		delete current_group;
		current_group = create_group();
	}else{
		win();
	}
	
}

SDL_Texture* Stacker::get_texture(int ID){
	switch(ID){
	case BLOCK_TEXTURE:
		return block_texture;
	case GRID_TEXTURE:
		return grid_texture;
	}
}
BlockGroup* Stacker::create_group(){

	int initial_position = (std::rand() % ( (constants::GRID_POINT_WIDTH) - 1 - (block_num - 1) + 1 ));

	return new BlockGroup(grid, this, Point(initial_position, current_level), block_num);
}

void Stacker::win(){
	playing = false;
	menu->set_game_state(Menu::WIN);
	menu->set_visible(true);
}

void Stacker::restart(){
	wait_time = 200;
	block_num = constants::MAX_BLOCK_NUM;
	current_level = 0;
	delete current_group;
	current_group = create_group();
	grid->reset();
	playing = true;

}