#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "GameMap.h"
#include "WindowRender.h"

GameMap::GameMap(WindowRender* p_window){
	
	//Loading map texutres
	Texture* grass1 = new Texture(p_window, "../res/gfx/ground_grass_1.png");
	Texture* grass2 = new Texture(p_window, "../res/gfx/ground_grass_2.png");
	Texture* pavement = new Texture(p_window, "../res/gfx/ground_pavement_1.png");
	Texture* brick1 = new Texture(p_window, "../res/gfx/brick_wall_1.png");

	//Stacking map textures in a vector
	m_textures.push_back(grass1);
	m_textures.push_back(grass2);
	m_textures.push_back(pavement);
	m_textures.push_back(brick1);
}

GameMap::~GameMap(){
	for(int i = m_textures.size(); i > 0; i--)
		// .size() returns the size of the vector, and thus we need do decrement it by 1 to get to the last variable
		delete m_textures[i-1];
}

SDL_Texture* GameMap::render_map(WindowRender* p_window){

	SDL_Renderer* renderer = p_window->get_renderer();
	SDL_Texture* mapTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, MapWidth * 64, MapHeight * 64);

	SDL_SetRenderTarget(renderer, mapTexture);
	SDL_RenderClear(renderer);

	for(int y = 0; y < MapHeight; y++){
		for(int x = 0; x < MapWidth; x++){

			SDL_Rect dst = {x * 64, y * 64, 64, 64};

			switch (m_Map[y][x]){
			case gr1:
				SDL_RenderCopy(renderer, m_textures[gr1]->get_texture(), nullptr, &dst);
				break;
			case gr2:
				SDL_RenderCopy(renderer, m_textures[gr2]->get_texture(), nullptr, &dst);
				break;
			case pv1 :
				SDL_RenderCopy(renderer, m_textures[pv1]->get_texture(), nullptr, &dst);
				break;
			case bw1:
				SDL_RenderCopy(renderer, m_textures[bw1]->get_texture(), nullptr, &dst);
				m_colliders.push_back(dst);
				break;
			}
		}
	}

	SDL_SetRenderTarget(renderer, nullptr);
	return mapTexture;
}

std::vector<SDL_Rect> GameMap::get_colliders(){
	return m_colliders;
}
