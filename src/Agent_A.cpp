#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Agent_A.h"

Agent_A::Agent_A(WindowRender* p_window){
	m_texture = new Texture(p_window, "../res/gfx/player_dot.png", true);
}

Agent_A::~Agent_A(){
	delete m_texture;
	m_texture = nullptr;
}
