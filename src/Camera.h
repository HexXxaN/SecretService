#pragma once
#include <SDL.h>
#include "Agent.h"

class Camera 
{
public:
	inline SDL_Rect get_camera() const { return m_camera; }
	inline SDL_Rect* get_cameraPtr() { return &m_camera; }
	inline void set_camera(SDL_Rect p_camera) { m_camera = p_camera; }

	void handle_camera(Agent* p_player, unsigned int p_levelWidth, unsigned int p_levelHeight);

private:
	SDL_Rect m_camera;
};