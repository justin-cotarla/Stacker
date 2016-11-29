#ifndef UTILITY_H
#define UTILITY_H

#include <string>

struct SDL_Texture;
struct SDL_Renderer;

namespace utility{
	SDL_Texture* load_texture(std::string path, SDL_Renderer* renderer);

}

#endif