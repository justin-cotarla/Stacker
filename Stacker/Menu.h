#ifndef MENU_H
#define MENU_H

struct SDL_Texture;
struct SDL_Renderer;

class Menu{

public:

	static const int MAX_OPTION = 1;
	static const int RESTART = 0;
	static const int QUIT = 1;

	static const int WIN = 0;
	static const int LOSE = 1;

	static const int UP = 0;
	static const int DOWN = 1;

	Menu(SDL_Texture* menu_texture);
	~Menu();

	//Switches between menu options
	void switch_option(int dir);

	//Executes current option
	void do_option();

	//Changes menu visibility
	void set_visible(bool v);

	//Renders menu on given surface
	void render(SDL_Renderer *gRenderer);

	//Sets menu message
	void set_game_state(int state);

	//Is menu visible
	bool is_visible();

private:

	static const int OPTION_X = 95;
	static const int OPTION_1_Y = 130;
	static const int OPTION_2_Y = 180;

	static const int OPTION_WIDTH = 110;
	static const int OPTION_HEIGHT = 30;

	SDL_Texture* menu_texture;

	bool visible;
	int game_state;
	int current_option;

};

#endif