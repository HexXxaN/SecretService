#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "WindowRender.h"

Texture::Texture(WindowRender* p_window, const char* p_filePath, bool p_colorKey) {

	SDL_Surface* loadedSurface = IMG_Load(p_filePath);

	if (loadedSurface == nullptr)
		std::cout << "Unable to load the texture! Error: " << SDL_GetError() << std::endl;
	else{
		SDL_SetColorKey(loadedSurface, p_colorKey, SDL_MapRGBA(loadedSurface->format, 0, 0xFF, 0xFF, 0xFF));

		m_texture = SDL_CreateTextureFromSurface(p_window->get_renderer(), loadedSurface);
		m_width = loadedSurface->w;
		m_height = loadedSurface->h;

		SDL_FreeSurface(loadedSurface);
	}
}

Texture::~Texture(){
	SDL_DestroyTexture(m_texture);
}

SDL_Texture* Texture::get_texture(){
	return m_texture;
}

SDL_Rect* Texture::get_src()
{
	return &m_src;
}