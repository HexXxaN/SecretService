#pragma once
#include <SDL.h>
#include <iostream>


class Timer {
public:
	inline unsigned int  get_current_time() { return SDL_GetTicks();}
	inline unsigned int get_start() { return m_start;}

	inline void set_to_current_time() { m_start = SDL_GetTicks(); }

private:
	unsigned int m_start = 0;
};