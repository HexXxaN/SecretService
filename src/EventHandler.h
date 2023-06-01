#pragma once
#include <SDL.h>
#include "Agent.h"

class EventHandler 
{
public:
	inline SDL_Event get_event() const { return m_event; }

	inline bool while_events() { return SDL_PollEvent(&m_event); };
	void handle_events(Agent* p_agent);

private:
	SDL_Event m_event;
};