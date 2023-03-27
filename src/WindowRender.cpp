#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

WindowRender::WindowRender(const char* title, int widith, int height) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widith, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* WindowRender::loadTexture(const char* filepath){
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filepath);
	return texture;
}

void WindowRender::clear(){
	SDL_RenderClear(renderer);
}

void WindowRender::render(SDL_Texture* texture){
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
}

void WindowRender::display(){
	SDL_RenderPresent(renderer);
}

void WindowRender::cleanUp(){
	SDL_DestroyWindow(window);
}
