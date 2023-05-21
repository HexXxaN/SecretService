#pragma once
#include <SDL.h>
#include "Camera.h"
#include "MovableCircularObject.h"
#include "Agent.h"


class WindowRender {
public:
	WindowRender(const char* p_title, int p_width, int p_height);
	~WindowRender();

	inline SDL_Renderer* get_renderer() { return m_renderer; }
	inline Camera* get_Camera() { return &m_Camera; }

	SDL_Texture* load_texture(const char* p_filePath);
	void clear();
	void render_texture(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst);
	void render_MovableCircularObject(SDL_Texture* p_texture, MovableCircularObject* p_entity);
	void display();

private:
	Camera m_Camera;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};