#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRenderer.h"
#include "Texture.h"
#include "StaticRectangularObject.h"
#include "Building.h"
#include "House.h"


#define LEVEL_WIDTH 50
#define LEVEL_HEIGHT 50


enum texture_enum{
	gr1, gr2, gr3, pv1, wf1, cf1, bw1, fin
};


class GameMap
{
public:
	GameMap(WindowRenderer* p_window);
	~GameMap();
	Texture* render_map_texture(WindowRenderer* p_window);

private:
	void load_textures(WindowRenderer* p_window);
	void load_staticRectangularObjects();
	void load_buildings(WindowRenderer* p_window);

private:
	std::vector<StaticRectangularObject*> m_staticRectangularObjects;
	std::vector<Building*> m_buildings;
	std::vector<Texture*> m_textures;
};