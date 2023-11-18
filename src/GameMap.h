#pragma once
#ifdef _WIN32
#include <SDL.h>
#endif
#ifdef __linux__
#include <SDL2/SDL.h>
#endif
#include <vector>
#include "WindowRenderer.h"
#include "Texture.h"
#include "StaticRectangularObject.h"
#include "Building.h"
#include "House.h"


enum texture_enum{
	gr1, gr2, gr3, pv1, wf1, cf1, bw1, fin
};


/// A class responsible for handling and creating the game map.
/// 
/// This class is responsible for creating map texture, storing hitboxes, 

class GameMap
{
public:
	GameMap() {}
	GameMap(const WindowRenderer& p_window);
	~GameMap();

	inline std::vector<StaticRectangularObject*> get_StaticRectangularObjects() const { return m_staticRectangularObjects; }
	inline std::vector<Building*> get_Buildings() const { return m_buildings; }

	/// A method responsible for creating the map texture.
	/// 
	/// This method creates map texture containing all the buildings, pavements and ground.
	/// <param name="p_window"> A class responsible for rendering. </param>
	/// <returns> Map texture. </returns>
	Texture render_map_texture(WindowRenderer& p_window, std::mt19937& p_gen);

private:

	/// A method responsible for loading textures.
	/// 
	///
	/// <param name="p_window"> A class responsible for rendering. </param>
	void load_textures(const WindowRenderer& p_window);

	/// A method responsible for adding pavements.
	/// 
	///
	void load_staticRectangularObjects();

	/// A method responsible for adding buildings.
	/// 
	/// 
	/// <param name="p_window"> A class responsible for rendering. </param>
	void load_buildings(const WindowRenderer& p_window);

private:
	std::vector<StaticRectangularObject*> m_staticRectangularObjects;
	std::vector<Building*> m_buildings;
	std::vector<Texture*> m_textures;
};