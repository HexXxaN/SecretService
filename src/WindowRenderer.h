#pragma once
#include <SDL.h>
#include "Point.h"
#include "Camera.h"
#include "MovableCircularObject.h"
#include "Agent.h"
#include "Enemy.h"


class WindowRenderer {
public:
	WindowRenderer() {}
	WindowRenderer(const char* p_title, int p_width, int p_height);
	~WindowRenderer();

	inline SDL_Renderer* get_renderer() const { return m_renderer; }
	inline Camera get_Camera() const { return m_Camera; }

	inline void set_Camera(SDL_Rect p_rect) { m_Camera.set_camera(p_rect); }

	inline SDL_Texture* load_texture(const char* p_filePath) const { return IMG_LoadTexture(m_renderer, p_filePath); } 
	inline void clear() const { SDL_RenderClear(m_renderer); }
	inline void display() const { SDL_RenderPresent(m_renderer); }
	inline void set_render_target(SDL_Texture* p_texture) const { SDL_SetRenderTarget(m_renderer, p_texture); }
	inline void handle_Camera(Agent* p_player, unsigned int p_LevelWidht, unsigned int p_LevelHeight) { m_Camera.handle_camera(p_player, p_LevelWidht, p_LevelHeight); }
	void render_static_texture(SDL_Texture* p_texture, Point p_origin) const;
	void render_static_texture(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst) const;
	void render_building(SDL_Texture* p_texture, Point p_origin, int p_width, int p_height) const;
	void render_entity(SDL_Texture* p_texture, MovableCircularObject* p_entity) const;


private:
	Camera m_Camera;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};