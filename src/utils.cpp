#pragma once
#include "utils.h"


void handle_camera(SDL_Rect& p_camera, Agent* p_player, int p_LevelWidth, int p_LevelHeight){
	float diameter = p_player->get_Diameter();
	//Focus the camera on the player
	p_camera.x = (p_player->get_dst()->x + int (0.5 + diameter / 2)) - p_camera.w / 2;	//int (0.5 + diameter / 2)) is used to round
	p_camera.y = (p_player->get_dst()->y + int (0.5 + diameter / 2)) - p_camera.h / 2;	//the diameter in case it's an odd number

	//Adjust the camera near the edges of the level
	if (p_camera.x < 0)
		p_camera.x = 0;
	if (p_camera.x + p_camera.w > p_LevelWidth)
		p_camera.x = p_LevelWidth - p_camera.w;
	if (p_camera.y < 0)
		p_camera.y = 0;
	if (p_camera.y + p_camera.h > p_LevelHeight)
		p_camera.y = p_LevelHeight - p_camera.h;
}
