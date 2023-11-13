#pragma once
#include <SDL.h>
#include <vector>
#include "Agent.h"
#include "Enemy.h"
#include "GameMap.h"

/// A class responsible for handling collisions.
/// 
/// This class handles collisions for both player and enemies.


class CollisionDetector
{
public:
	CollisionDetector() {}
	~CollisionDetector() {}

	void set_colliders(const GameMap& p_GameMap);

	/// A method responsible for moving the player and adjusting the position in case of collision.
	/// 
	/// If a collision with an obsticle occurs, the player position is adjusted to that obsticle in relation to previous player position.
	/// <param name="p_player"> A pointer to the Agent class. </param>
	void move_player(Agent* p_player) const;

	/// A method responsible for moving the Enemies and adjusting their position in case of collision.
	/// 
	/// This method is used for keeping the Enemies inside the walkable areas when the player is not detected as well as detecting collisions with obsticles.
	/// <param name="p_enemies"> A reference to the vector of Enemies. </param>
	void move_enemies(std::vector<Enemy>& p_enemies) const;

	/// A method responsible for detecting the player by Enemies with obsticle restriction.
	/// 
	/// If there's an obsticle between the player and the Enemy, the Enemy will not detect the player.
	/// <param name="p_player"> A pointer to the Agent class. </param>
	/// <param name="p_enemies"> A reference to the vector of Enemies. </param>
	void detect_player(Agent* p_player, std::vector<Enemy>& p_enemies) const;

	bool is_player_catched(Agent* p_player, const std::vector<Enemy>& p_enemies) const;

private:

	/// A direct method for detecting collisions for both agent and Enemies.
	/// 
	/// 
	/// <param name="p_entity"> A pointer to Agent or Enemy classes. </param>
	/// <param name="p_prev"> The position of the p_entity before moving it. </param>
	void detect_collisions(MovableCircularObject* p_entity, Point p_prev) const;

	/// This method checks if the Enemy is on at least one walking surface or not.
	/// 
	/// 
	/// <param name="p_enemy"> A reference to the Enemy. </param>
	/// <returns> True if the Enemy is within a walking surface and false when it is not. </returns>
	inline bool is_on_walkingSurface(const Enemy& p_enemy) const;

private:
	std::vector<SDL_Rect> m_colliders;
	std::vector<SDL_Rect> m_walkingSurfaces;
};