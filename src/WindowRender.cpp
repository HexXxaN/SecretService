#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

WindowRender::WindowRender(const char* title, int width, int height) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

WindowRender::~WindowRender(){
	SDL_DestroyWindow(window);
}

SDL_Texture* WindowRender::loadTexture(const char* filePath){
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath);
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