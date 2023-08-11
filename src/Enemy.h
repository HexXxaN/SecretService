#pragma once
#include <random>
#include "MovableCircularObject.h"


class Enemy : public MovableCircularObject
{
public:
	Enemy(Point p_origin);
	~Enemy() {}

	inline static bool was_player_spotted() { return m_wasPlayerSpotted; }
	inline static Point get_playerPos() { return m_playerPos; }
	unsigned short int get_movementTime() const { return m_movementTime; }
	inline Point get_originPoint() const { return m_originPoint; }

	inline static void set_wasPlayerSpotted() { m_wasPlayerSpotted = true; }
	inline static void set_playerPos(Point p_playerPos) { m_playerPos = p_playerPos; }

	bool detect_player(Point p_playerPos);
	void generate_movementTime();
	void move(Point p_point);
	void generate_movement_direction();

private:
	static bool m_wasPlayerSpotted;
	static Point m_playerPos;

	const short int m_DetectionRadius = 200;
	unsigned short int m_movementTime = 0;
	Point m_originPoint;
};