#pragma once
#include <SDL.h>
#include <vector>
#include "Agent.h"
#include "Enemy.h"
#include "GameMap.h"

class CollisionDetector
{
public:
	void set_colliders(GameMap* p_GameMap);

	void move_player(Agent* p_player) const;
	void move_enemies(std::vector<Enemy*>& p_enemies) const;
	void detect_player(Agent* p_player, std::vector<Enemy*>& p_enemies) const;

private:
	void detect_collisions(MovableCircularObject* p_entity, Point p_prev) const;
	inline bool is_on_walkingSurface(Enemy* p_enemy) const;

private:
	std::vector<SDL_Rect> m_colliders;
	std::vector<SDL_Rect> m_walkingSurfaces;
};