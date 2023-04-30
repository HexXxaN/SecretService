#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowRender.h"
#include "Texture.h"

#define LEVEL_WIDTH 30
#define LEVEL_HEIGHT 20

enum texture_names{
	gr1, gr2, pv1, bw1
};

class GameMap
{
public:
	GameMap(WindowRender* p_window);
	~GameMap();
	SDL_Texture* render_map(WindowRender* p_window);
	std::vector<SDL_Rect> get_colliders();
	void scale_colliders(int p_scaleX, int p_scaleY); //TODO

private:
	Uint8 m_Map[LEVEL_HEIGHT][LEVEL_WIDTH] = {
	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, bw1, gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1, gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 1
	gr2, gr1, gr2, gr2, gr1, gr1, gr2, gr1, pv1, bw1, gr2, gr1, gr2, gr2, gr1, gr1, gr2, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 2
	pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 3
	pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 4
	gr1, gr2, gr2, gr1, pv1, pv1, gr1, gr2, pv1, bw1, gr1, gr2, gr2, gr1, pv1, pv1, gr1, gr2, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 5
	gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr1, pv1, bw1, gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 6
	gr2, gr1, gr2, gr1, pv1, pv1, gr2, gr2, pv1, bw1, gr2, gr1, gr2, gr1, pv1, pv1, gr2, gr2, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 7
	gr2, gr2, gr1, gr2, pv1, pv1, gr1, gr1, pv1, bw1, gr2, gr2, gr1, gr2, pv1, pv1, gr1, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 8
	gr1, gr1, gr1, gr2, pv1, pv1, gr2, gr1, pv1, bw1, gr1, gr1, gr1, gr2, pv1, pv1, gr2, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 9
	gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr2, pv1, bw1, gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr2, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 10
	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, bw1, gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1, gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 11
	gr2, gr1, gr2, gr2, gr1, gr1, gr2, gr1, pv1, bw1, gr2, gr1, gr2, gr2, gr1, gr1, gr2, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 12
	pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 13
	pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 14
	gr1, gr2, gr2, gr1, pv1, pv1, gr1, gr2, pv1, bw1, gr1, gr2, gr2, gr1, pv1, pv1, gr1, gr2, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 15
	gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr1, pv1, bw1, gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 16
	gr2, gr1, gr2, gr1, pv1, pv1, gr2, gr2, pv1, bw1, gr2, gr1, gr2, gr1, pv1, pv1, gr2, gr2, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 17
	gr2, gr2, gr1, gr2, pv1, pv1, gr1, gr1, pv1, bw1, gr2, gr2, gr1, gr2, pv1, pv1, gr1, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 18
	gr1, gr1, gr1, gr2, pv1, pv1, gr2, gr1, pv1, bw1, gr1, gr1, gr1, gr2, pv1, pv1, gr2, gr1, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 19
	gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr2, pv1, bw1, gr2, gr2, gr1, gr1, pv1, pv1, gr1, gr2, pv1, pv1,	gr1, gr1, gr2, gr1, gr2, gr2, gr2, gr1, pv1, pv1,	// 20
	};
	std::vector<Texture*> m_textures;
	std::vector<SDL_Rect> m_colliders;
};