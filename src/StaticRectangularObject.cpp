#pragma once
#include "StaticRectangularObject.h"


void StaticRectangularObject::render_object(const WindowRenderer& p_window) {
	Point dst = { 0, 0 };

	for (int i = 0; i < m_w; i++) {
		dst.x = (m_origin.x + i) * 64;
		for (int j = 0; j < m_h; j++) {
			dst.y = (m_origin.y + j) * 64;
			p_window.render_static_texture(m_texture->get_texture(), dst);
		}
	}
}
