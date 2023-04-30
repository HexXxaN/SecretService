#pragma once
#include <SDL.h>
#include <vector>
#include "Texture.h"
#include "WindowRender.h"

class Agent
{
public:
	SDL_Rect* get_dst();
	int get_diameter();
	void move(std::vector<SDL_Rect> p_colliders);
	void handle_events(SDL_Event &p_event);

protected:
	const int m_Diameter = 55;
	int m_agent_vel = 5;
	int m_vel_x = 0, m_vel_y = 0;
	SDL_Rect m_dst = {0, 0, m_Diameter, m_Diameter};
};

