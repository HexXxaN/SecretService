#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"
#include "GameMap.h"
#include "Texture.h"
#include "Agent.h"
#include "Agent_A.h"

#define SCREEN_WIDTH 20*64
#define SCREEN_HEIGHT 10*64

int main(int argc, char *argv[]) {
	//Initialize SDL library
	SDL_Init(SDL_INIT_EVERYTHING);
	//Create window renderer called "Secret Service"
	WindowRender* window = new WindowRender("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);
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
		window->clear();
		window->render(mapTexture, nullptr, nullptr);
		player->move(colliders);
		window->render(playerTex->get_texture(), nullptr, player->get_dst());
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