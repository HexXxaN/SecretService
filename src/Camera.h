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
	Camera(const Camera&) = delete;
	~Camera() {}
	Camera& operator=(const Camera&) = delete;

	static Camera& get_instance()
	{
		static Camera instance;
		return instance;
	}

	inline SDL_Rect get_cameraRect() const { return m_cameraRect; }

	inline void set_cameraRect(const SDL_Rect& p_cameraRect) { m_cameraRect = p_cameraRect; }

	/// A method that adjusts the position of camera.
	/// 
	/// The camera is centered around the player and is restricted by level boundaries.
	/// <param name="p_player"> A pointer to the agent picked by the player. </param>
	/// <param name="p_levelWidth"> Level width. </param>
	/// <param name="p_levelHeight"> Level Height. </param>
	void handle_camera(Agent* p_player, unsigned int p_levelWidth, unsigned int p_levelHeight);

private:
	Camera() {}

private:
	SDL_Rect m_cameraRect;
};