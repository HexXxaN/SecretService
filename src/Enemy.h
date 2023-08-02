#pragma once
#include <random>
#include "MovableCircularObject.h"


class Enemy : public MovableCircularObject
{
public:
	Enemy(unsigned short int p_x, unsigned short int p_y);

	inline static bool was_player_spotted() { return m_wasPlayerSpotted; }
	inline static Point get_playerPos() { return m_playerPos; }
	inline static unsigned int get_detection_time() { return m_detectionTimer.get_start(); }
	inline static unsigned int get_current_time() { return m_detectionTimer.get_current_time(); }
	unsigned short int get_movementTime() const { return m_movementTime; }
	inline Point get_originPoint() const { return m_originPoint; }

	inline static void set_wasPlayerSpotted() { m_wasPlayerSpotted = true; }
	inline static void set_playerPos(Point p_playerPos) { m_playerPos = p_playerPos; }
	inline static void set_detection_time() { m_detectionTimer.set_to_current_time(); }

	bool detect_player(Point p_playerPos);
	void generate_movementTime();
	void move();
	void move(Point m_point);
	void generate_movement_direction();

private:
	static bool m_wasPlayerSpotted;
	static Point m_playerPos;
	static Timer m_detectionTimer;

	const short int m_DetectionRadius = 200;
	unsigned short int m_movementTime = 0;
	Point m_originPoint;
};