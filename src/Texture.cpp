#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "WindowRenderer.h"


Texture::Texture(const WindowRenderer& p_window, const char* p_filePath, unsigned short p_type, bool p_colorKey) {
	SDL_Surface* loadedSurface = IMG_Load(p_filePath);
	SDL_SetColorKey(loadedSurface, p_colorKey, SDL_MapRGBA(loadedSurface->format, 0, 0xFF, 0xFF, 0xFF));

	m_texture = SDL_CreateTextureFromSurface(p_window.get_renderer(), loadedSurface);
	m_type = p_type;

	SDL_FreeSurface(loadedSurface);
}

Texture::~Texture(){
	SDL_DestroyTexture(m_texture);
}

void Texture::create_texture(const WindowRenderer& p_window, int p_width, int p_height) {
	m_src.w = p_width;
	m_src.h = p_height;

	m_texture = SDL_CreateTexture(p_window.get_renderer(), SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, p_width, p_height);
}
