#pragma once
#include "Building.h"


class Warehouse : public Building
{
public:
	Warehouse() {}
	Warehouse(Point p_origin) { m_origin = p_origin; }
	~Warehouse() {}

	void generate_building(unsigned short int p_width, unsigned short int p_height);
};