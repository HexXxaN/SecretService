#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

WindowRender::WindowRender(const char* p_title, int p_width, int p_height) {
	m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
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

void WindowRender::render_texture(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst) {
	SDL_RenderCopy(m_renderer, p_texture, p_src, p_dst);
}

void WindowRender::render_entity(SDL_Texture* p_texture, SDL_Rect* p_dst, SDL_Rect* p_camera){
	SDL_Rect drawingRect = { p_dst->x - p_camera->x, p_dst->y - p_camera->y, p_dst->w, p_dst->h };
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &drawingRect);
}

void WindowRender::display(){
	SDL_RenderPresent(m_renderer);
}