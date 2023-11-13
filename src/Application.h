#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRenderer.h"
#include "GameMap.h"
#include "EventHandler.h"
#include "Texture.h"
#include "Agent_A.h"
#include "Agent_B.h"
#include "Macros.h"


class Application
{
public:
	Application()
		: m_window("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT) 
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	}
	~Application();

	void run();

private:
	void intro_loop();
	void main_loop();

private:
	WindowRenderer m_window;
	EventHandler m_events;
	Agent* m_player = nullptr;
	bool m_isGameRunning = true;
};