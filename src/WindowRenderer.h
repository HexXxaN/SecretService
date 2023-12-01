#pragma once
#ifdef _WIN32
#include <SDL.h>
#endif
#ifdef __linux__
#include <SDL2/SDL.h>
#endif
#include "Point.h"
#include "Camera.h"
#include "MovableCircularObject.h"
#include "Agent.h"
#include "Enemy.h"
#include "Macros.h"


/// A class responsible for rendering.
/// 
/// This class uses tools and functions provided by the SDL library.

class WindowRenderer {
public:
	WindowRenderer(const WindowRenderer&) = delete;
	~WindowRenderer();
	WindowRenderer& operator=(const WindowRenderer&) = delete;

	static WindowRenderer& get_instance()
	{
		static WindowRenderer instance("Secret Service", SCREEN_WIDTH, SCREEN_HEIGHT);
		return instance;
	}

	SDL_Renderer* get_renderer() const { return m_renderer; }
	SDL_Rect get_camera() const { return m_Camera.get_cameraRect(); }

	inline void set_Camera(const SDL_Rect& p_rect) { m_Camera.set_cameraRect(p_rect); }

	/// A method responsible for loading textures from a filepath.
	/// 
	///
	/// <param name="p_filePath"> A constant array of chars to the specific directory. </param>
	/// <returns> A pointer to heap allocated SDL_Texture. </returns>
	inline SDL_Texture* load_texture(const char* p_filePath) const { return IMG_LoadTexture(m_renderer, p_filePath); } 

	/// A method responsible for clearing the current rendering buffer.
	/// 
	/// 
	inline void clear() const { SDL_RenderClear(m_renderer); }

	/// A method responsible for displaying the current rendering buffer.
	/// 
	///
	inline void display() const { SDL_RenderPresent(m_renderer); }

	/// A method responsible for changing the rendering target.
	/// 
	/// This method is mainly used to create a new texture by rendering other textures onto it.
	/// <param name="p_texture"> A pointer to SDL_Texture to render. If the render targed is supposed to by the window use nullptr. </param>
	inline void set_render_target(SDL_Texture* p_texture) const { SDL_SetRenderTarget(m_renderer, p_texture); }

	/// A method responsible for handling Camera.
	/// 
	/// This method handles the Camere class attribute to center it on a player and adjust its position in relation to the map boundaries.
	/// <param name="p_player"> A pointer to the Agent class. </param>
	/// <param name="p_LevelWidht"> Level width. </param>
	/// <param name="p_LevelHeight"> Level height. </param>
	inline void handle_Camera(Agent* p_player, unsigned int p_LevelWidht, unsigned int p_LevelHeight) { m_Camera.handle_camera(p_player, p_LevelWidht, p_LevelHeight); }

	/// A method responsible for rendering a static texture on a certain destination point.
	/// 
	/// This method renders the texture with the top left corner being on the origin point. 
	/// <param name="p_texture"> A pointer to SDL_Texture to render. </param>
	/// <param name="p_origin"> Destination point. </param>
	void render_static_texture(SDL_Texture* p_texture, Point p_origin) const;

	/// A method responsible for rendering a fragment of a texture to a certain destination area.
	/// 
	///
	/// <param name="p_texture"> A pointer to SDL_Texture to render. </param>
	/// <param name="p_src"> SDL_Rect area of the texture to render. </param>
	/// <param name="p_dst"> SDL_Rect area to render onto. </param>
	void render_static_texture(SDL_Texture* p_texture, SDL_Rect* p_src, SDL_Rect* p_dst) const;

	/// A method for rendering buildings.
	/// 
	/// 
	/// <param name="p_texture"> A pointer to SDL_Texture to render. </param>
	/// <param name="p_origin"> The point where the texture is supposed to be rendered onto. </param>
	/// <param name="p_width"> The width of the texture. </param>
	/// <param name="p_height"> The height of the texture. </param>
	void render_building(SDL_Texture* p_texture, Point p_origin, int p_width, int p_height) const;

	/// A method for rendering Agent and Enemy classes.
	/// 
	/// 
	/// <param name="p_texture"> A pointer to SDL_Texture to render. </param>
	/// <param name="p_entity"> A pointer to Agent or Enemy classes. </param>
	void render_entity(SDL_Texture* p_texture, MovableCircularObject* p_entity) const;

private:
	WindowRenderer(const char* p_title, int p_width, int p_height);

private:
	Camera& m_Camera = Camera::get_instance();
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};