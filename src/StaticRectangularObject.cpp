#pragma once
#include "StaticRectangularObject.h"

StaticRectangularObject::StaticRectangularObject(unsigned short p_type, Point p_origin, unsigned short int p_width, unsigned short int p_height, Texture* p_texture) {
	m_type = p_type;
	m_origin = p_origin;
	m_w = p_width;
	m_h = p_height;
	m_texture = p_texture;
}

StaticRectangularObject::~StaticRectangularObject() {
}

void StaticRectangularObject::render_object(WindowRenderer* p_window) {
	Point dst = { 0, 0 };

	for (int i = 0; i < m_w; i++) {
		dst.x = (m_origin.x + i) * 64;
		for (int j = 0; j < m_h; j++) {
			dst.y = (m_origin.y + j) * 64;
			p_window->render_static_texture(m_texture->get_texture(), dst);
		}
	}
}
