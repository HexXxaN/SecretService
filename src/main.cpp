#pragma once
#include "SDL.h"

int main(int argc, char *argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Secret Service", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 768, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderClear(renderer);
	while(1)
		SDL_RenderPresent(renderer);

	return 0;
}