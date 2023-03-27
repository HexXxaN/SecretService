#pragma once
#include <SDL.h>
#include "WindowRender.h"

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);	// initializing SDL library
	WindowRender window("Secret Service v1.0", 1280, 720);

	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
	}

	window.cleanUp();	// destroy the game window created by the window object

	SDL_Quit();

	return 0;
}