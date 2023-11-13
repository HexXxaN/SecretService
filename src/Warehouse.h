#pragma once
#include "Building.h"


/// A class responsible for creating warehouses.
/// 
/// This class generates generic warehouses with brick walls and concrete floor.

class Warehouse : public Building
{
public:
	Warehouse() {}
	Warehouse(Point p_origin) { m_origin = p_origin; }
	~Warehouse() {}


	/// A method responsible for generating warehouse.
	/// 
	/// This method generates a warehouse with 3 exits of a size determined by the warehouse size.
	/// <param name="p_width"> The width of the warehouse in 64x64 tiles. </param>
	/// <param name="p_height"> The height of the warehouse in 64x64 tiles. </param>
	void generate_building(unsigned short int p_width, unsigned short int p_height);
};