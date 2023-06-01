#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"
#include "Texture.h"
#include "StaticRectangularObject.h"


#define LEVEL_WIDTH 30
#define LEVEL_HEIGHT 20


enum texture_enum{
	gr1, gr2, gr3, pv1, wf1, bw1, fin
};


class GameMap
{
public:
	GameMap(WindowRender* p_window);
	~GameMap();
	SDL_Texture* render_map(WindowRender* p_window);

private:
	void load_textures(WindowRender* p_window);
	void load_staticRectangularObjects();

private:

	std::vector<StaticRectangularObject*> m_staticRectangularObjects;
	std::vector<Texture*> m_textures;
};