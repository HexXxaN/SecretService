#pragma once
#include "Warehouse.h"


void Warehouse::generate_building(unsigned short int p_width, unsigned short int p_height) {
	//if the dimensions are too small
	if (p_width < 7 || p_height < 7)
		return;

	m_w = p_width;
	m_h = p_height;

	//if p_width is an odd number
	if (p_width % 2) {
		m_horizontalWallWidth = p_width / 2;
		m_horizontalWallX = p_width / 2 + 1;
	}
	else {
		m_horizontalWallWidth = p_width / 2 - 1;
		m_horizontalWallX = p_width / 2 + 1;
	}

	//if p_height is an odd number
	if (p_height % 2) {
		m_verticalWallHeight = p_height / 2 - 1;
		m_verticalWallY = p_height / 2 + 1;
	}
	else {
		m_verticalWallHeight = p_height / 2 - 2;
		m_verticalWallY = p_height / 2 + 1;
	}

	StaticRectangularObject* floor = new StaticRectangularObject(texture_type::concrete_floor, { 0, 0 }, p_width, p_height);

	StaticRectangularObject* horizontalWall1 = new StaticRectangularObject(texture_type::wall, { 0 , 0 }, p_width, 1);
	StaticRectangularObject* horizontalWall2 = new StaticRectangularObject(texture_type::wall, { 0, p_height - 1}, m_horizontalWallWidth, 1);
	StaticRectangularObject* horizontalWall3 = new StaticRectangularObject(texture_type::wall, { m_horizontalWallX, p_height - 1 }, m_horizontalWallWidth, 1);

	StaticRectangularObject* verticalWall1 = new StaticRectangularObject(texture_type::wall, { 0, 1 }, 1, m_verticalWallHeight);
	StaticRectangularObject* verticalWall2 = new StaticRectangularObject(texture_type::wall, { 0, m_verticalWallY }, 1, m_verticalWallHeight);
	StaticRectangularObject* verticalWall3 = new StaticRectangularObject(texture_type::wall, { p_width - 1 , 1 }, 1, p_height - 2);

	m_components.reserve(7);

	m_components.push_back(floor);

	m_components.push_back(horizontalWall1);
	m_components.push_back(horizontalWall2);
	m_components.push_back(horizontalWall3);

	m_components.push_back(verticalWall1);
	m_components.push_back(verticalWall2);
	m_components.push_back(verticalWall3);
}