#pragma once
#include <SDL.h>
#include <vector>
#include "Agent.h"
#include "GameMap.h"

class CollisionDetector
{
public:

	void set_colliders(GameMap* p_GameMap);

	void manage_collisions(Agent* p_player);

private:
	std::vector<SDL_Rect> m_colliders;
	std::vector<SDL_Rect> m_walkingSurfaces;
};