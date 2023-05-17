#pragma once
#include <SDL.h>
#include <vector>
#include "Texture.h"
#include "WindowRender.h"

#include <iostream>

struct Point {
	short int x, y;
};

class Agent
{
public:
	short int get_diameter();
	void move(std::vector<SDL_Rect> p_colliders);
	void handle_events(SDL_Event &p_event);
	SDL_Rect* get_dst();
	Point get_dotCenter();
	virtual void handle_special_ability() {}

protected:
	const short int m_Diameter = 55;
	short int m_agent_vel = 5;
	unsigned int m_timer = 0;
	SDL_Rect m_dst = { 0, 0, m_Diameter, m_Diameter };
	Point m_dotCenter;
	bool m_moveUp = false;
	bool m_moveDown = false;
	bool m_moveLeft = false;
	bool m_moveRight = false;
};