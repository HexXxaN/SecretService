#pragma once
#include "Building.h"


class House : public Building 
{
public:
	House(Point p_origin) { m_origin = p_origin; }

	void generate_building(unsigned short int p_width, unsigned short int p_height);
};