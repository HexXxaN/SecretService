#pragma once
#include <vector>
#include <random>
#include <SDL.h>
#include <SDL_image.h>
#include "GameMap.h"
#include "Macros.h"
#include "WindowRenderer.h"
#include "Texture.h"
#include "Warehouse.h"


GameMap::GameMap(const WindowRenderer& p_window){
	load_textures(p_window);
	load_buildings(p_window);
	load_staticRectangularObjects();
}

GameMap::~GameMap() {

	for (auto& building : m_buildings)
		delete building;

	for (auto& object : m_staticRectangularObjects)
		delete object;

	for (auto& texture : m_textures)
		delete texture;
}

Texture GameMap::render_map_texture(WindowRenderer& p_window) {

	Texture mapTexture;
	mapTexture.create_texture(p_window, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);

	p_window.set_render_target(mapTexture.get_texture());
	p_window.clear();


	//Generate grass
	SDL_Rect dst;
	int groundTex;

	for (int i = 0; i < LEVEL_WIDTH; i++) {
		for (int j = 0; j < LEVEL_HEIGHT; j++) {

			dst = { i * 64, j * 64, 64, 64 };

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> dist(1, 3);

			groundTex = dist(gen);

			switch (groundTex) {
			case 1:
				p_window.render_static_texture(m_textures[gr1]->get_texture(), nullptr, &dst);
				break;
			case 2:
				p_window.render_static_texture(m_textures[gr2]->get_texture(), nullptr, &dst);
				break;
			case 3:
				p_window.render_static_texture(m_textures[gr3]->get_texture(), nullptr, &dst);
				break;
			}
		}
	}

	//p_window.render_static_texture(m_textures[gr3]->get_texture(), nullptr, &src);

	for (auto& object : m_staticRectangularObjects)
		object->render_object(p_window);

	for (auto& building : m_buildings)
		building->render_object(p_window);

	p_window.set_render_target(nullptr);

	return mapTexture;
}

void GameMap::load_textures(const WindowRenderer& p_window) {
	//Loading map texutres
	Texture* grass1 = new Texture(p_window, "../res/gfx/ground_grass_1.png", texture_type::grass1);
	Texture* grass2 = new Texture(p_window, "../res/gfx/ground_grass_2.png", texture_type::grass2);
	Texture* grass3 = new Texture(p_window, "../res/gfx/ground_grass_3.png", texture_type::grass3);
	Texture* pavement = new Texture(p_window, "../res/gfx/ground_pavement_1.png", texture_type::pavement);
	Texture* wall = new Texture(p_window, "../res/gfx/brick_wall_1.png", texture_type::wall);
	Texture* wooden_floor = new Texture(p_window, "../res/gfx/wooden_floor.png", texture_type::wooden_floor);
	Texture* concrete_floor = new Texture(p_window, "../res/gfx/concrete_floor.png", texture_type::concrete_floor);
	Texture* finish = new Texture(p_window, "../res/gfx/finish.png", texture_type::finish);

	m_textures.reserve(8);

	//Stacking map textures in a vector
	m_textures.push_back(grass1);
	m_textures.push_back(grass2);
	m_textures.push_back(grass3);
	m_textures.push_back(pavement);
	m_textures.push_back(wooden_floor);
	m_textures.push_back(concrete_floor);
	m_textures.push_back(wall);
	m_textures.push_back(finish);
}

void GameMap::load_staticRectangularObjects() {
	StaticRectangularObject* pavement1 = new StaticRectangularObject(texture_type::pavement, { 0, 0 }, LEVEL_WIDTH, 2, m_textures[pv1]);
	StaticRectangularObject* pavement2 = new StaticRectangularObject(texture_type::pavement, { 19, 2 }, 2, LEVEL_HEIGHT, m_textures[pv1]);
	StaticRectangularObject* pavement3 = new StaticRectangularObject(texture_type::pavement, { 0 , m_buildings[0]->get_origin().y + m_buildings[0]->get_verticalWallHeight() + 1 },
		pavement2->get_origin().x, 2, m_textures[pv1]);
	StaticRectangularObject* pavement4 = new StaticRectangularObject(texture_type::pavement, { m_buildings[0]->get_origin().x + m_buildings[0]->get_horizontalWallWidth(), 2 },
		2, LEVEL_HEIGHT, m_textures[pv1]);
	StaticRectangularObject* pavement5 = new StaticRectangularObject(texture_type::pavement, { 0 , m_buildings[1]->get_origin().y + m_buildings[1]->get_verticalWallHeight() + 1 },
		LEVEL_WIDTH, 2, m_textures[pv1]);
	StaticRectangularObject* pavement6 = new StaticRectangularObject(texture_type::pavement, { 0 , m_buildings[2]->get_origin().y + m_buildings[2]->get_verticalWallHeight() + 1 },
		pavement2->get_origin().x, 2, m_textures[pv1]);
	StaticRectangularObject* pavement7 = new StaticRectangularObject(texture_type::pavement, { 21, m_buildings[3]->get_origin().y + m_buildings[3]->get_verticalWallHeight() + 1 }, m_buildings[3]->get_width(), 2, m_textures[pv1]);
	StaticRectangularObject* pavement8 = new StaticRectangularObject(texture_type::pavement, { LEVEL_WIDTH - 2, 0 }, 2, LEVEL_HEIGHT, m_textures[pv1]);

	m_staticRectangularObjects.reserve(8);

	m_staticRectangularObjects.push_back(pavement1);
	m_staticRectangularObjects.push_back(pavement2);
	m_staticRectangularObjects.push_back(pavement3);
	m_staticRectangularObjects.push_back(pavement4);
	m_staticRectangularObjects.push_back(pavement5);
	m_staticRectangularObjects.push_back(pavement6);
	m_staticRectangularObjects.push_back(pavement7);
	m_staticRectangularObjects.push_back(pavement8);

	//m_staticRectangularObjects.push_back(wall1);
}

void GameMap::load_buildings(const WindowRenderer& p_window) {
	Building* house1 = new House({ 4, 5 });
	Building* house2 = new House({ 4,20 });
	Building* house3 = new House({ 4, 35 });

	Building* warehouse1 = new Warehouse({ 25, 5 });
	Building* warehouse2 = new Warehouse({ 25, 29 });

	house1->generate_building(10, 10);
	house2->generate_building(10, 10);
	house3->generate_building(10, 12);

	warehouse1->generate_building(16, 16);
	warehouse2->generate_building(16, 18);

	m_buildings.reserve(5);

	m_buildings.push_back(house1);
	m_buildings.push_back(house2);
	m_buildings.push_back(house3);

	m_buildings.push_back(warehouse1);
	m_buildings.push_back(warehouse2);

	for (auto& building : m_buildings) {
		building->set_components_texture(m_textures);
		building->create_building_texture(p_window);
	}
}
