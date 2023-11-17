#pragma once
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif
#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif
#include "WindowRenderer.h"


enum texture_type {
	undef, player, enemy, grass1, grass2, grass3, pavement, wall, wooden_floor, concrete_floor, finish 
};


/// A class responsible for storing textures.
/// 
///

class Texture
{
public:
	Texture() {}
	Texture(const WindowRenderer& p_window, const char* p_filePath, unsigned short p_type = undef, bool p_colorKey = false);
	~Texture();

	inline short int get_type() const { return m_type; }
	inline SDL_Rect get_src() const { return m_src; }
	inline SDL_Texture* get_texture() const { return m_texture; }

	/// A method responsible for creating a new texture.
	/// 
	/// This method creates a new texture of given dimentions.
	/// <param name="p_window"> A class responsible for rendering. </param>
	/// <param name="p_width"> Texture width. </param>
	/// <param name="p_height"> Texture height. </param>
	void create_texture(const WindowRenderer& p_window, int p_width, int p_height);

private:
	unsigned short m_type = undef;
	SDL_Rect m_src = { 0, 0, 32, 32 };
	SDL_Texture* m_texture = nullptr;
};