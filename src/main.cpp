#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Macros.h"
#include "WindowRenderer.h"
#include "GameMap.h"
#include "Texture.h"
#include "Agent.h"
#include "Agent_A.h"
#include "Agent_B.h"
#include "Enemy.h"
#include "EventHandler.h"
#include "CollisionDetector.h"


int main(int argc, char* argv[]) {
	//Initialize SDL library
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	//Create window renderer called "Secret Service"
	WindowRenderer window("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);

	//Create game map
	GameMap gameMap(window);

	//Create player
	Agent* player = nullptr;

	//Load player texture
	Texture playerTex(window, "../res/gfx/player_dot.png", texture_type::player, true);
	//Create enemy texture
	Texture enemyTex(window, "../res/gfx/enemy_dot.png", texture_type::enemy, true);
	//Create intro texture
	Texture intro(window, "../res/gfx/intro.png");

	//Create map texture using gameMap object
	Texture mapTexture = gameMap.render_map_texture(window);

	CollisionDetector collisionDetector;
	collisionDetector.set_colliders(gameMap);

	//Create a variable that's true when the intro is running
	bool introRunning = true;
	//Create a variable that's true when the game is running to run the main loop
	bool gameRunning = true;

	//Create an object that's responsible for handling events
	EventHandler events;

	//Create a vector of enemies
	std::vector<Enemy> enemies;
	enemies.reserve(2);
	enemies.emplace_back(Enemy({ 500, 64 }));
	enemies.emplace_back(Enemy({ 1000, 64 }));

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

		window.clear();
		window.render_static_texture(intro.get_texture(), nullptr, nullptr);
		window.display();
	}
	//________________END OF INTRO____________________

	player->set_dotCenter({ 64, 64 });
	SDL_Rect camera;

	//______________MAIN LOOP__________________
	while (gameRunning) {
		while (events.while_events()) {
			if (events.get_event().type == SDL_QUIT)
				gameRunning = false;

			events.handle_events(player);
		}

		collisionDetector.move_player(player);
		collisionDetector.move_enemies(enemies);
		collisionDetector.detect_player(player, enemies);
		player->handle_special_ability();
		window.handle_Camera(player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
		window.clear();
		camera = window.get_Camera().get_camera();
		window.render_static_texture(mapTexture.get_texture(), &camera, nullptr);
		window.render_entity(playerTex.get_texture(), player);
		for (auto& enemy : enemies)
			window.render_entity(enemyTex.get_texture(), &enemy);
		window.display();
	}
	//_________END OF THE MAIN LOOP_____________

	delete player;

	//Close SDL library
	SDL_Quit();

	return 0;
}