#pragma once
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif
#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif
#include "Agent.h"

/// A class responsible for handling the area to render.
/// 
///


class Camera 
{
public:
	Camera() {}
	Camera(const Camera& p_other)
		: m_camera(p_other.get_camera()) {}
	~Camera() {}

	inline SDL_Rect get_camera() const { return m_camera; }

	inline void set_camera(SDL_Rect p_camera) { m_camera = p_camera; }

	/// A method that adjusts the position of camera.
	/// 
	/// The camera is centered around the player and is restricted by level boundaries.
	/// <param name="p_player"> A pointer to the agent picked by the player. </param>
	/// <param name="p_levelWidth"> Level width. </param>
	/// <param name="p_levelHeight"> Level Height. </param>
	void handle_camera(Agent* p_player, unsigned int p_levelWidth, unsigned int p_levelHeight);

private:
	SDL_Rect m_camera;
};