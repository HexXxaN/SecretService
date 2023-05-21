#pragma once
#include <SDL.h>
#include <vector>
#include "MovableCircularObject.h"
#include "Collider.h"

class Agent : public MovableCircularObject
{
public:
	inline bool get_moveUp() const { return m_moveUp; }
	inline bool get_moveDown() const { return m_moveDown; }
	inline bool get_moveLeft() const { return m_moveLeft; };
	inline bool get_moveRight() const { return m_moveRight; }
	inline unsigned int get_timer() const { return m_timer; }

	inline void set_moveUp(bool p_val) { m_moveUp = p_val; }
	inline void set_moveDown(bool p_val) { m_moveDown = p_val; }
	inline void set_moveLeft(bool p_val) { m_moveLeft = p_val; }
	inline void set_moveRight(bool p_val) { m_moveRight = p_val; }
	inline void set_timer(unsigned int p_val) { m_timer = p_val; }

	virtual void handle_special_ability() {}
	void move(Collider* p_Colliders);

protected:
	bool m_moveUp = false;
	bool m_moveDown = false;
	bool m_moveLeft = false;
	bool m_moveRight = false;
	unsigned int m_timer = 0;
};