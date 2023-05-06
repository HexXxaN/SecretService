#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "WindowRender.h"
#include "GameMap.h"
#include "Texture.h"
#include "Agent.h"
#include "Agent_A.h"
#include "Agent_B.h"
#include "Enemy.h"
#include "utils.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


int main(int argc, char* argv[]) {
	//Initialize SDL library
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	//Create window renderer called "Secret Service"
	WindowRender* window = new WindowRender("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);

	//Create camera
	SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Create game map
	GameMap* gameMap = new GameMap(window);

	//Create player
	Agent* player = new Agent_A();

	//Create player texture
	Texture* playerTex = new Texture(window, "../res/gfx/player_dot.png", true);
	//Create enemy texture
	Texture* enemyTex = new Texture(window, "../res/gfx/enemy_dot.png", true);

	//Create map texture using gameMap object. The object contains colliders required to detect collisions
	SDL_Texture* mapTexture = gameMap->render_map(window);

	//Create vector of colliders created by gameMap object
	std::vector<SDL_Rect> colliders = gameMap->get_colliders();

	//_________________TEST__________________
	Enemy* en1 = new Enemy({ 100, 100 }, { 300, 500 });

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

		player->move(colliders);
		player->handle_special_ability();
		en1->move();
		handle_camera(camera, player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
		window->clear();
		window->render_map(mapTexture, &camera, nullptr);
		window->render_entity(enemyTex->get_texture(), en1->get_dst(), &camera);
		window->render_entity(playerTex->get_texture(), player->get_dst(), &camera);
		window->display();
	}
	//_________END OF THE MAIN LOOP_____________


	SDL_DestroyTexture(mapTexture);

	delete enemyTex;
	delete en1;
	delete playerTex;
	delete player;
	delete gameMap;
	delete window;
	
	//Close SDL library
	SDL_Quit();

	return 0;
}