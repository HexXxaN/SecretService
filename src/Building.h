#pragma once
#include "StaticRectangularObject.h"
#include "Texture.h"

class Building : public StaticRectangularObject
{
public:
	Building() {};
	~Building();

	void set_components_texture(std::vector<Texture*> p_textures);

	inline unsigned short get_horizontalWallWidth(){ return m_horizontalWallWidth; }
	inline unsigned short get_verticalWallHeight() { return m_verticalWallHeight; }
	inline unsigned short get_horizontalWallX() { return m_horizontalWallX; }
	inline unsigned short get_verticalWallY() { return m_verticalWallY; }
	inline std::vector<StaticRectangularObject*> get_components() { return m_components; }

	virtual void generate_building(unsigned short int p_width, unsigned short int p_height) {};
	void create_building_texture(WindowRenderer* p_window);
	void render_object(WindowRenderer* p_window);

protected:	
	unsigned short m_horizontalWallWidth = 0;
	unsigned short m_verticalWallHeight = 0;
	unsigned short m_horizontalWallX = 0;
	unsigned short m_verticalWallY = 0;

	std::vector<StaticRectangularObject*> m_components;
	Texture* m_texture = nullptr;
};