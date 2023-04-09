#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"
#include "GameMap.h"
#include "Texture.h"
#include "Agent.h"
#include "Agent_A.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(int argc, char *argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	WindowRender* window = new WindowRender("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);
	GameMap* gameMap = new GameMap(window);
	Agent_A* player = new Agent_A(window);

	SDL_Texture* mapTexture = gameMap->render_map(window);

	delete gameMap;

	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRunning = false;

			player->handle_events(event);
		}
		window->clear();
		window->render(mapTexture, nullptr, nullptr);
		player->move();
		window->render(player->get_texture(), nullptr, player->get_dst());
		window->display();
	}

	delete player;
	delete window;
	
	SDL_Quit();
	return 0;
}