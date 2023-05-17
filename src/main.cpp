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


#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900


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
	Agent* player = nullptr;

	//Load player texture
	Texture* playerTex = new Texture(window, "../res/gfx/player_dot.png", true);
	//Create enemy texture
	Texture* enemyTex = new Texture(window, "../res/gfx/enemy_dot.png", true);
	//Create intro texture
	Texture* intro = new Texture(window, "../res/gfx/intro.png");

	//Create map texture using gameMap object. The object contains colliders required to detect collisions
	SDL_Texture* mapTexture = gameMap->render_map(window);

	//Create vector of colliders created by gameMap object
	std::vector<SDL_Rect> colliders = gameMap->get_colliders();

	//_________________TEST__________________
	std::vector<Enemy*> enemies = create_enemies();

	//Create a variable that's true when the intro is running
	bool introRunning = true;
	//Create a variable that's true when the game is running to run the main loop
	bool gameRunning = true;
	//Create a variable that's responsible for handling events
	SDL_Event event;
	
	//________________INTRO____________________
	while (introRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				introRunning = false;
				gameRunning = false;
			}

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_1:
					player = new Agent_A();
					introRunning = false;
					break;
				case SDLK_2:
					player = new Agent_B();
					introRunning = false;
					break;
				}
			}

		}

		window->clear();
		window->render_texture(intro->get_texture(), nullptr, nullptr);
		window->display();
	}

	delete intro;

	//______________MAIN LOOP__________________
	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRunning = false;

			player->handle_events(event);
		}

		player->move(colliders);
		player->handle_special_ability();
		for (auto& enemy : enemies)
			enemy->move();
		handle_camera(camera, player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
		window->clear();
		window->render_texture(mapTexture, &camera, nullptr);
		for (auto &enemy : enemies)
			window->render_entity(enemyTex->get_texture(), enemy->get_dst(), &camera);
		window->render_entity(playerTex->get_texture(), player->get_dst(), &camera);
		window->display();
	}
	//_________END OF THE MAIN LOOP_____________

	SDL_DestroyTexture(mapTexture);
	
	for (auto& enemy : enemies)
		delete enemy;

	delete player;
	delete enemyTex;
	delete playerTex;
	delete gameMap;
	delete window;
	
	//Close SDL library
	SDL_Quit();

	return 0;
}