#pragma once
#include <SDL.h>
#include <iostream>


class Timer {
public:
	Timer() {}
	Timer(const Timer& p_other)
		: m_start(p_other.get_start()) {}
	~Timer() {}

	inline unsigned int  get_current_time() const { return SDL_GetTicks();}
	inline unsigned int get_start() const { return m_start;}

	inline void set_to_current_time() { m_start = SDL_GetTicks(); }

private:
	unsigned int m_start = 0;
};