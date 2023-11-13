#pragma once
#include "Point.h"
#include "Timer.h"

/// Basic class for all movable entities.
///
/// This class contains all the data shared by both agent and enemy classes.


class MovableCircularObject 
{
public:
	MovableCircularObject() {}
	virtual ~MovableCircularObject() {}

	inline unsigned short int get_Diameter() const { return m_Diameter; }
	inline unsigned short int get_radius() const { return m_radius; }
	inline Point get_dotCenter() const { return m_dotCenter; }
	Timer get_Timer() { return m_Timer; }

	void set_dotCenter(Point p_dotCenter) { m_dotCenter = p_dotCenter; }

	/// A method responsible for moving entities around the map.
	/// 
	/// This method moves entities in 4 directions: up, down, left, and right. The movement is restricted by the boundaries of the map.
	void move();

protected:
	const unsigned int m_Diameter = 55;
	unsigned short int m_radius = m_Diameter / 2;
	short unsigned int m_vel = 5;
	bool m_moveUp = false;
	bool m_moveDown = false;
	bool m_moveLeft = false;
	bool m_moveRight = false;
	Point m_dotCenter = { 100, 100 };
	Timer m_Timer;
};