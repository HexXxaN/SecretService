#pragma once
#include <SDL.h>
#include "GameMap.h"
#include "Agent.h"
#include "Agent_A.h"


void handle_camera(SDL_Rect& p_camera, Agent* p_player, int p_LevelWidth, int p_LevelHeight);