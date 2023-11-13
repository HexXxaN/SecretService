#pragma once
#include "StaticRectangularObject.h"
#include "Texture.h"

/// A virtual class that contains all the date shared by House and Warehouse classes.
/// 
/// This is a basic class for buildings in game that allows polymorphism.


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

	/// A virtual method for generating buildings.
	/// 
	/// This method allows polymorphism for generating both House and Warehouse objects.
	/// <param name="p_width"> The width of the building in 64x64 tiles. </param>
	/// <param name="p_height"> The height of the building in 64x64 tiles. </param>
	virtual void generate_building(unsigned short int p_width, unsigned short int p_height) = 0;

	/// A method for creating building texture.
	/// 
	/// This method creates the building texture from its components.
	/// <param name="p_window"> Class responsible for rendering. </param>
	void create_building_texture(const WindowRenderer& p_window);

	/// A method for rendering the building.
	/// 
	/// <param name="p_window"> Class responsible for rendering. </param>
	void render_object(const WindowRenderer& p_window) override;

protected:	
	unsigned short m_horizontalWallWidth = 0;
	unsigned short m_verticalWallHeight = 0;
	unsigned short m_horizontalWallX = 0;
	unsigned short m_verticalWallY = 0;

	std::vector<StaticRectangularObject*> m_components;
};