#pragma once
#include "Building.h"


/// A class responsible for creating houses.
/// 
/// This class generates generic houses with brick walls and wooden floor.

class House : public Building 
{
public:
	House() {}
	House(Point p_origin) { m_origin = p_origin; }
	~House() {}

	/// A method responsible for generating house.
	/// 
	/// This method generates a house with 4 exits of a size determined by the house size.
	/// <param name="p_width"> The width of the house in 64x64 tiles. </param>
	/// <param name="p_height"> The height of the house in 64x64 tiles. </param>
	void generate_building(unsigned short int p_width, unsigned short int p_height) override;
};