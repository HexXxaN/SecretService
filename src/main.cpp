#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "WindowRenderer.h"
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
	WindowRenderer* window = new WindowRenderer("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);

	//Create game map
	GameMap* gameMap = new GameMap(window);

	//Create player
	Agent* player = nullptr;

	//Load player texture
	Texture* playerTex = new Texture(window, "../res/gfx/player_dot.png", texture_type::player, true);
	//Create enemy texture
	Texture* enemyTex = new Texture(window, "../res/gfx/enemy_dot.png", texture_type::enemy, true);
	//Create intro texture
	Texture* intro = new Texture(window, "../res/gfx/intro.png");

	//Create map texture using gameMap object
	Texture* mapTexture = gameMap->render_map_texture(window);

	CollisionDetector* collisionDetector = new CollisionDetector();
	collisionDetector->set_colliders(gameMap);

	//Create a variable that's true when the intro is running
	bool introRunning = true;
	//Create a variable that's true when the game is running to run the main loop
	bool gameRunning = true;

	//Create an object that's responsible for handling events
	EventHandler events;

	std::vector<Enemy*> enemies;
	Enemy* en1 = new Enemy(500, 64);
	enemies.push_back(en1);
	
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
		window->render_static_texture(intro->get_texture(), nullptr, nullptr);
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

		collisionDetector->move_player(player);
		collisionDetector->move_enemies(enemies);
		collisionDetector->detect_player(player, enemies);
		player->handle_special_ability();
		window->get_Camera()->handle_camera(player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
		window->clear();
		SDL_Rect camera_tmp = window->get_Camera()->get_camera();
		window->render_static_texture(mapTexture->get_texture(), &camera_tmp, nullptr);
		window->render_entity(playerTex->get_texture(), player);
		for (auto& enemy : enemies)
			window->render_entity(enemyTex->get_texture(), enemy);
		window->display();
	}
	//_________END OF THE MAIN LOOP_____________

	delete collisionDetector;
	delete player;
	delete enemyTex;
	delete playerTex;
	delete gameMap;
	delete mapTexture;
	delete window;

	for (auto& enemy : enemies)
		delete enemy;
	
	//Close SDL library
	SDL_Quit();

	return 0;
}