#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRenderer.h"


WindowRenderer::WindowRenderer(const char* p_title, int p_width, int p_height) {
	m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	m_Camera.set_camera({ 0 , 0, p_width, p_height });
}

WindowRenderer::~WindowRenderer(){
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void WindowRenderer::render_static_texture(SDL_Texture* p_texture, Point p_origin) {
	SDL_Rect dst = { p_origin.x, p_origin.y, 64, 64 };
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &dst);
}

void WindowRenderer::render_static_texture(SDL_Texture* p_mapTexture, SDL_Rect* p_src, SDL_Rect* p_dst){
	SDL_RenderCopy(m_renderer, p_mapTexture, p_src, p_dst);
}

void WindowRenderer::render_building(SDL_Texture* p_texture, Point p_origin, int p_width, int p_height) {
	SDL_Rect dst = { p_origin.x * 64, p_origin.y * 64, p_width * 64, p_height * 64 };
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &dst);
}

void WindowRenderer::render_entity(SDL_Texture* p_texture, MovableCircularObject* p_entity){
	unsigned short int diameter = p_entity->get_Diameter();
	unsigned short int radius = p_entity->get_radius();
	Point entityCenter = p_entity->get_dotCenter();
	SDL_Rect camera = m_Camera.get_camera();

	SDL_Rect drawingRect = { entityCenter.x - radius - camera.x, entityCenter.y - radius - camera.y, diameter, diameter};
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &drawingRect);
}
