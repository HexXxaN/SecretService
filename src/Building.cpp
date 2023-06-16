#pragma once
#include "Building.h"
#include "WindowRenderer.h"
#include "Texture.h"

Building::~Building()
{
	for (auto& component : m_components)
		delete component;

	delete m_texture;
}

void Building::set_components_texture(std::vector<Texture*> p_textures)
{
	for (auto& component : m_components) {
		for (auto& texture : p_textures) {
			if (component->get_type() == texture->get_type()) {
				component->set_texture(texture);
				break;
			}
		}
	}
}

void Building::create_building_texture(WindowRenderer* p_window) {

	m_texture = new Texture();
	m_texture->create_texture(p_window, m_w * 64, m_h * 64);

	p_window->set_render_target(m_texture->get_texture());
	p_window->clear();

	for (auto& component : m_components)
		component->render_object(p_window);

	p_window->set_render_target(nullptr);
}

void Building::render_object(WindowRenderer* p_window) {
	p_window->render_building(m_texture->get_texture(), m_origin, m_w, m_h);
}
