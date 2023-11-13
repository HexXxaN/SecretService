#pragma once
#include <random>
#include "MovableCircularObject.h"

/// A class for enemies.
/// 
///


class Enemy : public MovableCircularObject
{
public:
	Enemy() {}
	Enemy(Point p_origin);
	~Enemy() {}

	inline static bool was_player_spotted() { return m_wasPlayerSpotted; }
	inline static Point get_playerPos() { return m_playerPos; }
	unsigned short int get_movementTime() const { return m_movementTime; }
	inline Point get_originPoint() const { return m_originPoint; }

	inline static void set_wasPlayerSpotted() { m_wasPlayerSpotted = true; }
	inline static void set_playerPos(Point p_playerPos) { m_playerPos = p_playerPos; }

	/// A method that detects the player.
	/// 
	/// This method checks if the distance between the player and the enemy is closer than the detection radius of the enemy.
	/// <param name="p_playerPos"> The position of the player. </param>
	/// <returns> True when the player is closer than the detection radius and flase when the player is not within the detection range. </returns>
	bool detect_player(Point p_playerPos);

	/// A method that generates movement time of the enemy while the player is not detected.
	/// 
	/// This method generates the movement time between 100 and 500 ms.
	void generate_movementTime();

	/// A method for moving the enemy to a certain destination point.
	/// 
	/// <param name="p_point"> Destination point. </param>
	void move(Point p_point);

	/// A method that generates the movement direction of the enemy.
	/// 
	/// The enemy can move only up, down, left, and right.
	void generate_movement_direction();

private:
	static bool m_wasPlayerSpotted;
	static Point m_playerPos;

	const short int m_DetectionRadius = 300;
	unsigned short int m_movementTime = 0;
	Point m_originPoint = { 0, 0 };
};