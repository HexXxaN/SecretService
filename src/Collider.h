#pragma once
#include <SDL.h>
#include <vector>

class Collider 
{
public:
	std::vector<SDL_Rect> get_colliders() { return m_colliders; }

	inline void set_colliders(std::vector<SDL_Rect> p_colliders) { m_colliders = p_colliders; }

private:
	std::vector<SDL_Rect> m_colliders;
};