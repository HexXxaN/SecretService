#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);	// initializing SDL library

	WindowRender*  window = nullptr;
	window = new WindowRender("Secret Service", 1920, 1080);
	
	SDL_Texture* grassTexture = window->loadTexture("../res/gfx/test.png");
	SDL_Rect rectGrassTexture = { 0, 0, 32, 32 };
	SDL_Rect rectPavementTexture = { 32, 0, 32, 32 };

	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
		window->clear();
		for(int y = 0; y < 1080; y += 64)
		{
			for (int x = 0; x < 1920; x += 64)
			{
				SDL_Rect dst = {x, y, 64, 64};
				if (x == 64 * 5 || x == 64 * 6  || y == 64 * 8 || y == 64 * 7) {
					window->render(grassTexture, &rectPavementTexture, &dst);
				}
				else {
					window->render(grassTexture, &rectGrassTexture, &dst);
				}
			}
		}
		window->display();
	}

	delete window;	// destroy the game window created by the window object

	SDL_Quit();

	return 0;
}