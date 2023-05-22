#pragma once
#include <SDL.h>
#include <vector>
#include "MovableCircularObject.h"
#include "Timer.h"


class Agent : public MovableCircularObject
{
public:
	inline bool get_moveUp() const { return m_moveUp; }
	inline bool get_moveDown() const { return m_moveDown; }
	inline bool get_moveLeft() const { return m_moveLeft; };
	inline bool get_moveRight() const { return m_moveRight; }
	inline Timer* get_Timer() { return &m_Timer; }

	inline void set_moveUp(bool p_val) { m_moveUp = p_val; }
	inline void set_moveDown(bool p_val) { m_moveDown = p_val; }
	inline void set_moveLeft(bool p_val) { m_moveLeft = p_val; }
	inline void set_moveRight(bool p_val) { m_moveRight = p_val; }

	bool can_be_detected() { return m_canBeDetected; }
	virtual void handle_special_ability() {}
	void move();

protected:
	bool m_canBeDetected = true;
	bool m_moveUp = false;
	bool m_moveDown = false;
	bool m_moveLeft = false;
	bool m_moveRight = false;
	Timer m_Timer;
};