#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"

#define MapWidth 20
#define MapHeight 10

enum texture_names
{
	gr1, gr2, pv1, bw1
};

class GameMap
{
public:
	GameMap(WindowRender* &p_window);
	~GameMap();
	SDL_Texture* render_map(WindowRender* &p_window);
private:
	int m_Map[MapHeight][MapWidth] = {
	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, bw1, gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, bw1,	// 1
	gr2, gr1, gr2, gr2, gr1, gr1, gr2, gr1, pv1, bw1, gr2, gr1, gr2, gr2, gr1, gr1, gr2, gr1, pv1, bw1,	// 2
	pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, bw1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, bw1,	// 3
	pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, bw1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, bw1,	// 4
	gr1, gr2, gr2, gr1, pv1, pv1, gr1, gr2, pv1, bw1, gr1, gr2, gr2, gr1, pv1, pv1, gr1, gr2, pv1, bw1,	// 5
	gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr1, pv1, bw1, gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr1, pv1, bw1,	// 6
	gr2, gr1, gr2, gr1, pv1, pv1, gr2, gr2, pv1, bw1, gr2, gr1, gr2, gr1, pv1, pv1, gr2, gr2, pv1, bw1,	// 7
	gr2, gr2, gr1, gr2, pv1, pv1, gr1, gr1, pv1, bw1, gr2, gr2, gr1, gr2, pv1, pv1, gr1, gr1, pv1, bw1,	// 8
	gr1, gr1, gr1, gr2, pv1, pv1, gr2, gr1, pv1, bw1, gr1, gr1, gr1, gr2, pv1, pv1, gr2, gr1, pv1, bw1,	// 9
	gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr2, pv1, bw1, gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr2, pv1, bw1	// 10
	};
	std::vector<SDL_Texture*> m_textures;
};