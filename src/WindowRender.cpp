#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

WindowRender::WindowRender(const char* p_title, int p_width, int p_height) {
	m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	m_Camera.set_camera({ 0 , 0, p_width, p_height });
}

WindowRender::~WindowRender(){
	SDL_DestroyWindow(m_window);
}

SDL_Texture* WindowRender::load_texture(const char* p_filePath){
	return IMG_LoadTexture(m_renderer, p_filePath);
}

void WindowRender::clear(){
	SDL_RenderClear(m_renderer);
}

void WindowRender::render_texture(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst) {
	SDL_RenderCopy(m_renderer, p_texture, p_src, p_dst);
}

void WindowRender::render_MovableCircularObject(SDL_Texture* p_texture, MovableCircularObject* p_entity){
	unsigned short int diameter = p_entity->get_Diameter();
	unsigned short int radius = p_entity->get_radius();
	Point playerCenter = p_entity->get_dotCenter();
	SDL_Rect camera = m_Camera.get_camera();

	SDL_Rect drawingRect = { playerCenter.x - radius - camera.x, playerCenter.y - radius - camera.y, diameter, diameter};
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &drawingRect);
}

void WindowRender::display(){
	SDL_RenderPresent(m_renderer);
}