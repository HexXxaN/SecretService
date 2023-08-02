#pragma once
#include <string>
#include "Point.h"
#include "Texture.h"
#include "WindowRenderer.h"


class StaticRectangularObject 
{
public:
	StaticRectangularObject() {};
	StaticRectangularObject(unsigned short p_type, Point p_origin, unsigned short int p_width, unsigned short int p_height, Texture* p_texture = nullptr);
	virtual ~StaticRectangularObject();

	inline unsigned short get_type() const { return m_type; }
	inline Point get_origin() const { return m_origin; }
	inline unsigned short get_width() const { return m_w; }
	inline unsigned short get_height() const { return m_h; }

	inline void set_origin(Point p_point) { m_origin = p_point; }
	inline void set_width(unsigned short int p_width) { m_w = p_width; }
	inline void set_height(unsigned short int p_height) { m_h = p_height; }
	inline void set_texture(Texture* p_texture) { m_texture = p_texture; }

	void render_object(WindowRenderer* p_window);

protected:
	unsigned short m_type = undef;
	Point m_origin = { 0, 0 };
	unsigned short m_w = 0, m_h = 0;
	Texture* m_texture = nullptr;
};