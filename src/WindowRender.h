#pragma once
#include <SDL.h>


class WindowRender {
public:
	WindowRender(const char* p_title, int p_width, int p_height);
	~WindowRender();
	SDL_Texture* load_texture(const char* p_filePath);
	SDL_Renderer* get_renderer();
	void clear();
	void render_map(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst);
	void render_entity(SDL_Texture* p_texture, SDL_Rect* p_dst, SDL_Rect* p_camera);
	void display();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};