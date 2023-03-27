#pragma once
#include "WindowRender.h"

WindowRender::WindowRender(const char* title, int widith, int height) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widith, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

//SDL_Texture* WindowRender::loadTexture(const char* filePath){
//	SDL_Texture* texture = nullptr;
//	texture = IMG_LoadTexture(renderer, filePath);
//	return texture;
//}

void WindowRender::cleanUp(){
	SDL_DestroyWindow(window);
}
