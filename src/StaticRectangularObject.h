#pragma once
#include <string>
#include "Point.h"
#include "Texture.h"
#include "WindowRender.h"


class StaticRectangularObject 
{
public:
	StaticRectangularObject(std::string p_ID, Point p_origin, unsigned short int p_width, unsigned short int p_height, bool p_isSolid = false, Texture* p_texture = nullptr);
	~StaticRectangularObject();

	inline std::string get_ID() { return m_ID; }
	inline Point get_origin() { return m_origin; }
	inline short unsigned int get_width() { return m_w; }
	inline short unsigned int get_height() { return m_h; }
	inline bool is_solid() { return m_isSolid; }

	inline void set_ID(std::string p_ID) { m_ID = p_ID; }
	inline void set_origin(Point p_point) { m_origin = p_point; }
	inline void set_width(unsigned short int p_width) { m_w = p_width; }
	inline void set_height(unsigned short int p_height) { m_h = p_height; }
	inline void set_texture(Texture* p_texture) { m_texture = p_texture; }

	void render_object(WindowRender* p_window);

private:
	std::string m_ID = "";
	Point m_origin = { 0, 0 };
	short unsigned int m_w = 0, m_h = 0;
	Texture* m_texture = nullptr;
	bool m_isSolid = false;
};