#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRenderer.h"
#include "Texture.h"
#include "StaticRectangularObject.h"
#include "Building.h"
#include "House.h"


enum texture_enum{
	gr1, gr2, gr3, pv1, wf1, cf1, bw1, fin
};


class GameMap
{
public:
	GameMap() {}
	GameMap(const WindowRenderer& p_window);
	~GameMap();

	inline std::vector<StaticRectangularObject*> get_StaticRectangularObjects() const { return m_staticRectangularObjects; }
	inline std::vector<Building*> get_Buildings() const { return m_buildings; }
	Texture render_map_texture(WindowRenderer& p_window);

private:
	void load_textures(const WindowRenderer& p_window);
	void load_staticRectangularObjects();
	void load_buildings(const WindowRenderer& p_window);

private:
	std::vector<StaticRectangularObject*> m_staticRectangularObjects;
	std::vector<Building*> m_buildings;
	std::vector<Texture*> m_textures;
};