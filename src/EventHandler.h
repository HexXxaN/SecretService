#pragma once
#ifdef _WIN32
#include <SDL.h>
#endif
#ifdef __linux__
#include <SDL2/SDL.h>
#endif
#include "Agent.h"


/// A class responsible for handling events.
/// 
/// This class checks inputs from mouse end keybord.


class EventHandler 
{
public:
	EventHandler() {}
	~EventHandler() {}

	inline SDL_Event get_event() const { return m_event; }

	/// A method that checks if inputs are queued.
	/// 
	/// 
	/// <returns> True if there are inputs to process and false if there are not. </returns>
	inline bool while_events() { return SDL_PollEvent(&m_event); };

	/// A method responsible for handling events.
	/// 
	/// This method handles input events that affect the Agent.
	/// <param name="p_agent"> A pointer to Agent class picked by player. </param>
	void handle_events(Agent* p_agent);

private:
	SDL_Event m_event;
};