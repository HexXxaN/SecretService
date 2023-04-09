#pragma once
#include <SDL.h>
#include "Texture.h"
#include "WindowRender.h"

class Agent
{
public:
	SDL_Texture* get_texture();
	SDL_Rect* get_dst();
	void move();
	void handle_events(SDL_Event &p_event);

protected:
	const int m_diameter = 64;
	int m_agent_vel = 10;
	int m_vel_x = 0, m_vel_y = 0;
	Texture* m_texture = nullptr;
	SDL_Rect m_dst = { 0, 0, 64, 64 };
};

