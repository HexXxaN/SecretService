#pragma once
#include "Building.h"


class House : public Building 
{
public:
	House() {}
	House(Point p_origin) { m_origin = p_origin; }
	~House() {}

	void generate_building(unsigned short int p_width, unsigned short int p_height);
};