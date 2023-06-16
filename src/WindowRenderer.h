#pragma once
#include <SDL.h>
#include "Point.h"
#include "Camera.h"
#include "MovableCircularObject.h"
#include "Agent.h"


class WindowRenderer {
public:
	WindowRenderer(const char* p_title, int p_width, int p_height);
	~WindowRenderer();

	inline SDL_Renderer* get_renderer() { return m_renderer; }
	inline Camera* get_Camera() { return &m_Camera; }

	inline SDL_Texture* load_texture(const char* p_filePath) { return IMG_LoadTexture(m_renderer, p_filePath); }
	inline void clear() { SDL_RenderClear(m_renderer); }
	inline void display() { SDL_RenderPresent(m_renderer); }
	inline void set_render_target(SDL_Texture* p_texture) { SDL_SetRenderTarget(m_renderer, p_texture); }
	void render_static_texture(SDL_Texture* p_texture, Point p_origin);
	void render_static_texture(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst);
	void render_building(SDL_Texture* p_texture, Point p_origin, int p_width, int p_height);
	void render_player(SDL_Texture* p_texture, Agent* p_player);

private:
	Camera m_Camera;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};