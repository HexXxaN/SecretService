#pragma once
#include "StaticRectangularObject.h"
#include "Texture.h"


class Building : public StaticRectangularObject
{
public:
	Building() {};
	virtual ~Building();

	inline unsigned short get_horizontalWallWidth() const { return m_horizontalWallWidth; }
	inline unsigned short get_verticalWallHeight() const { return m_verticalWallHeight; }
	inline unsigned short get_horizontalWallX() const { return m_horizontalWallX; }
	inline unsigned short get_verticalWallY() const { return m_verticalWallY; }
	inline std::vector<StaticRectangularObject*> get_components() const { return m_components; }

	void set_components_texture(const std::vector<Texture*>& p_textures);

	virtual void generate_building(unsigned short int p_width, unsigned short int p_height) = 0;
	void create_building_texture(const WindowRenderer& p_window);
	void render_object(const WindowRenderer& p_window);

protected:	
	unsigned short m_horizontalWallWidth = 0;
	unsigned short m_verticalWallHeight = 0;
	unsigned short m_horizontalWallX = 0;
	unsigned short m_verticalWallY = 0;

	std::vector<StaticRectangularObject*> m_components;
};