#include <SDL.h>
#include "Menu.h"

Menu::Menu(SDL_Texture* menu_texture):
 menu_texture(menu_texture){

}

Menu::~Menu(){

}

void Menu::switch_option(int dir){
	switch(dir){
	case UP:
		if(current_option + 1 > MAX_OPTION){
			current_option = 0;
		}else{
			current_option++;
		}
		break;
	case DOWN:
		if(current_option - 1 < 0){
			current_option = MAX_OPTION;
		}else{
			current_option--;
		}
		break;
	}
}

void Menu::set_game_state(int state){
	game_state = state;
}

void Menu::set_visible(bool v){
	visible = v;
}

void Menu::render(SDL_Renderer *gRenderer){

	int y;

	switch(current_option){
	case RESTART:
		y = OPTION_1_Y;
		break;
	case QUIT:
		y = OPTION_2_Y;
		break;
	}
	SDL_Rect rect = {OPTION_WIDTH, OPTION_HEIGHT, OPTION_X, y};

}