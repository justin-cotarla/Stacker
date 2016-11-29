#include "Utility.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

namespace utility{

	SDL_Texture* load_texture(std::string path, SDL_Renderer* renderer){
		SDL_Texture* texture = NULL;

		//Load image at specified path
		SDL_Surface* loaded_surface = IMG_Load( path.c_str() );
		if( loaded_surface == NULL ){
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());

		}else{
			//Create texture from surface pixels
			texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);

			if(texture == NULL){

			  printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loaded_surface);
		}

		return texture;
	}
}