#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "WindowRender.h"
#include "Agent.h"

class Agent_A : public Agent
{
public:
	Agent_A(WindowRender* p_window);
	~Agent_A();

private:
};