#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "utils.h"
#include "WindowRender.h"
#include "GameMap.h"
#include "Texture.h"
#include "Agent.h"
#include "Agent_A.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


int main(int argc, char* argv[]) {
	//Initialize SDL library
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window renderer called "Secret Service"
	WindowRender* window = new WindowRender("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);

	//Creage camera
	SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Create game map
	GameMap* gameMap = new GameMap(window);

	//Create player
	Agent_A* player = new Agent_A();

	//Create player texture
	Texture* playerTex = new Texture(window, "../res/gfx/player_dot.png", true);

	//Create map texture using gameMap object. The object contains all the colliders required to detect collisions
	SDL_Texture* mapTexture = gameMap->render_map(window);

	//Create vector of colliders created by gameMap object
	std::vector<SDL_Rect> colliders = gameMap->get_colliders();


	//Create a variable that's true when the game is running to run the main loop
	bool gameRunning = true;
	//Create a variable that's responsible for handling events
	SDL_Event event;

	//______________MAIN LOOP__________________
	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRunning = false;

			player->handle_events(event);
		}
		//If the window is not minimized handle rendering
			player->move(colliders);
			handle_camera(camera, player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
			window->clear();
			window->render(mapTexture, &camera, nullptr);
			window->render_player(playerTex->get_texture(), player->get_dst(), &camera);
			window->display();
	}
	//_________END OF THE MAIN LOOP_____________

	delete playerTex;
	delete player;
	delete gameMap;
	delete window;
	
	//Close SDL library
	SDL_Quit();
	return 0;
}