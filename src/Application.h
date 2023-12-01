#pragma once
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif
#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif
#include <random>
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
	Application(const Application&) = delete;
	~Application();
	Application& operator=(const Application&) = delete;

	static void run() 
	{ 
		static Application app;
		app.i_run();
	}

private:
	Application() { SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS); }

	void i_run();
	void i_intro_loop();
	void i_main_loop();

private:
	WindowRenderer& m_window = WindowRenderer::get_instance();
	EventHandler& m_events = EventHandler::get_instance();
	Agent* m_player = nullptr;
	bool m_isGameRunning = true;
};