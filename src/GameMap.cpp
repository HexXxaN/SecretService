#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "GameMap.h"
#include "WindowRender.h"

GameMap::GameMap(WindowRender* p_window){
	this->load_textures(p_window);
	this->load_staticRectangularObjects();
}

GameMap::~GameMap(){
	for (auto& object : m_staticRectangularObjects) {
		delete object;
		object = nullptr;
	}

	for (auto& texture : m_textures) {
		delete texture;
		texture = nullptr;
	}
}

SDL_Texture* GameMap::render_map(WindowRender* p_window){

	SDL_Renderer* renderer = p_window->get_renderer();
	SDL_Texture* mapTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);

	SDL_SetRenderTarget(renderer, mapTexture);
	SDL_RenderClear(renderer);

	SDL_Rect map = { 0, 0, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64 };

	p_window->render_static_texture(m_textures[gr3]->get_texture(), nullptr, &map);

	for (auto& object : m_staticRectangularObjects)
		object->render_object(p_window);

	SDL_SetRenderTarget(renderer, nullptr);
	return mapTexture;
}

void GameMap::load_textures(WindowRender* p_window) {
	//Loading map texutres
	Texture* grass1 = new Texture(p_window, "../res/gfx/ground_grass_1.png");
	Texture* grass2 = new Texture(p_window, "../res/gfx/ground_grass_2.png");
	Texture* grass3 = new Texture(p_window, "../res/gfx/ground_grass_3.png");
	Texture* pavement = new Texture(p_window, "../res/gfx/ground_pavement_1.png");
	Texture* brick1 = new Texture(p_window, "../res/gfx/brick_wall_1.png");
	Texture* wooden_floor = new Texture(p_window, "../res/gfx/wooden_floor.png");
	Texture* finish = new Texture(p_window, "../res/gfx/finish.png");


	//Stacking map textures in a vector
	m_textures.push_back(grass1);
	m_textures.push_back(grass2);
	m_textures.push_back(grass3);
	m_textures.push_back(pavement);
	m_textures.push_back(wooden_floor);
	m_textures.push_back(brick1);
	m_textures.push_back(finish);
}

void GameMap::load_staticRectangularObjects()
{
	StaticRectangularObject* pavement1 = new StaticRectangularObject("pavement", { 0, 0 }, LEVEL_WIDTH, 2, false, m_textures[pv1]);
	StaticRectangularObject* pavement2 = new StaticRectangularObject("pavement", { 15, 2 }, 2, LEVEL_HEIGHT, false, m_textures[pv1]);

	StaticRectangularObject* wall1 = new StaticRectangularObject("wall", { 17, 2 }, 1, LEVEL_HEIGHT, true, m_textures[bw1]);

	m_staticRectangularObjects.push_back(pavement1);
	m_staticRectangularObjects.push_back(pavement2);

	m_staticRectangularObjects.push_back(wall1);
}