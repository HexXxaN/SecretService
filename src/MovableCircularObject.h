#pragma once
#include "Point.h"
#include "Timer.h"

class MovableCircularObject 
{
public:
	inline unsigned short int get_Diameter() const { return m_Diameter; }
	inline unsigned short int get_radius() const { return m_radius; }
	inline Point get_dotCenter() const { return m_dotCenter; }
	Timer* get_Timer() { return &m_Timer; }

	void set_dotCenter(Point p_dotCenter) { m_dotCenter = p_dotCenter; }

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