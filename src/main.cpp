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
#include "EventHandler.h"
#include "CollisionDetector.h"


#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900


int main(int argc, char* argv[]) {
	//Initialize SDL library
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	//Create window renderer called "Secret Service"
	WindowRender* window = new WindowRender("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);

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

	CollisionDetector* collisionDetector = new CollisionDetector();
	collisionDetector->set_colliders(gameMap->get_colliders());

	//Create a variable that's true when the intro is running
	bool introRunning = true;
	//Create a variable that's true when the game is running to run the main loop
	bool gameRunning = true;
	//Create a variable that's responsible for handling events

	EventHandler events;
	
	//________________INTRO____________________
	while (introRunning) {
		while (events.while_events()) {
			if (events.get_event().type == SDL_QUIT) {
				introRunning = false;
				gameRunning = false;
			}

			if (events.get_event().type == SDL_KEYDOWN) {
				switch (events.get_event().key.keysym.sym) {
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

		while (events.while_events()) {
			if (events.get_event().type == SDL_QUIT)
				gameRunning = false;

			events.handle_events(player);
		}

		collisionDetector->manage_collisions(player);
		player->handle_special_ability();
		window->get_Camera()->handle_camera(player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
		window->clear();
		SDL_Rect camera_tmp = window->get_Camera()->get_camera();
		window->render_texture(mapTexture, &camera_tmp, nullptr);
		window->render_MovableCircularObject(playerTex->get_texture(), player);
		window->display();
	}
	//_________END OF THE MAIN LOOP_____________

	SDL_DestroyTexture(mapTexture);

	delete collisionDetector;
	delete player;
	delete enemyTex;
	delete playerTex;
	delete gameMap;
	delete window;
	
	//Close SDL library
	SDL_Quit();

	return 0;
}