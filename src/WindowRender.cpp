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
	SDL_DestroyRenderer(m_renderer);
}

void WindowRender::render_static_texture(SDL_Texture* p_texture, Point p_origin) {
	SDL_Rect dst = { p_origin.x, p_origin.y, 64, 64 };
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &dst);
}

void WindowRender::render_static_texture(SDL_Texture* p_mapTexture, SDL_Rect* p_src, SDL_Rect* p_dst){
	SDL_RenderCopy(m_renderer, p_mapTexture, p_src, p_dst);
}

void WindowRender::render_player(SDL_Texture* p_texture, Agent* p_player){
	unsigned short int diameter = p_player->get_Diameter();
	unsigned short int radius = p_player->get_radius();
	Point playerCenter = p_player->get_dotCenter();
	SDL_Rect camera = m_Camera.get_camera();

	SDL_Rect drawingRect = { playerCenter.x - radius - camera.x, playerCenter.y - radius - camera.y, diameter, diameter};
	SDL_RenderCopy(m_renderer, p_texture, nullptr, &drawingRect);
}
