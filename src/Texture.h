#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRenderer.h"


enum texture_type {
	undef, player, enemy, grass1, grass2, grass3, pavement, wall, wooden_floor, concrete_floor, finish 
};


class Texture
{
public:
	Texture() {}
	Texture(WindowRenderer* p_window, const char* p_filePath, unsigned short p_type = undef, bool p_colorKey = false);
	~Texture();

	inline short int get_type() const { return m_type; }
	inline SDL_Rect get_src() const { return m_src; }
	inline SDL_Texture* get_texture() { return m_texture; }

	void create_texture(WindowRenderer* p_window, int p_width, int p_height);

private:
	unsigned short m_type = undef;
	SDL_Rect m_src = { 0, 0, 32, 32 };
	SDL_Texture* m_texture = nullptr;
};