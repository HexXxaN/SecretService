#pragma once
#include "Building.h"


class Warehouse : public Building
{
public:
	Warehouse(Point p_origin) { m_origin = p_origin; }

	void generate_building(unsigned short int p_width, unsigned short int p_height);
};