#pragma once
#include <string>
#include "Point.h"
#include "Texture.h"
#include "WindowRenderer.h"

/// A class for static rectangular objects.
/// 
/// This class can be used alone (for pavements, walls etc.) and it contains all the data that is shared by Building class.


class StaticRectangularObject 
{
public:
	StaticRectangularObject() {};
	StaticRectangularObject(unsigned short p_type, Point p_origin, unsigned short int p_width, unsigned short int p_height, Texture* p_texture = nullptr)
		: m_type(p_type), m_origin(p_origin), m_w(p_width), m_h(p_height), m_texture(p_texture) {}

	virtual ~StaticRectangularObject() {}

	inline unsigned short get_type() const { return m_type; }
	inline Point get_origin() const { return m_origin; }
	inline unsigned short get_width() const { return m_w; }
	inline unsigned short get_height() const { return m_h; }

	inline void set_origin(Point p_point) { m_origin = p_point; }
	inline void set_width(unsigned short int p_width) { m_w = p_width; }
	inline void set_height(unsigned short int p_height) { m_h = p_height; }
	inline void set_texture(Texture* p_texture) { m_texture = p_texture; }

	/// A method used to render the object onto the game map.
	/// 
	/// This method fills the designated area with a texture m_texture attribute points to.
	/// <param name="p_window"> An object of a class that's responsible for rendering. </param>
	virtual void render_object(const WindowRenderer& p_window);

protected:
	unsigned short m_type = undef;
	Point m_origin = { 0, 0 };
	unsigned short m_w = 0, m_h = 0;
	Texture* m_texture = nullptr;
};