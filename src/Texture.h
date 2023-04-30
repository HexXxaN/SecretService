#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

class Texture
{
public:
	Texture(WindowRender* p_window, const char* p_filePath, bool p_colorKey = false);
	~Texture();
	SDL_Texture* get_texture();
	SDL_Rect* get_src();

private:
	SDL_Rect m_src = {0, 0, 32, 32};
	SDL_Texture* m_texture = nullptr;
};