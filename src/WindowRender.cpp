#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

WindowRender::WindowRender(const char* p_title, int p_width, int p_height) {
	m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

WindowRender::~WindowRender(){
	SDL_DestroyWindow(m_window);
}

SDL_Texture* WindowRender::load_texture(const char* p_filePath){
	SDL_Texture* texture = IMG_LoadTexture(m_renderer, p_filePath);
	return texture;
}

SDL_Renderer* WindowRender::get_renderer(){
	return m_renderer;
}

void WindowRender::clear(){
	SDL_RenderClear(m_renderer);
}

void WindowRender::render(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst){
	SDL_RenderCopy(m_renderer, p_texture, p_src, p_dst);
}

void WindowRender::display(){
	SDL_RenderPresent(m_renderer);
}