#pragma once
#include <SDL.h>
#include <vector>
#include "Agent.h"

class CollisionDetector
{
public:
	std::vector<SDL_Rect> get_colliders() { return m_colliders; }

	inline void set_colliders(std::vector<SDL_Rect> p_colliders) { m_colliders = p_colliders; }

	void manage_collisions(Agent* p_player);

private:
	std::vector<SDL_Rect> m_colliders;
};