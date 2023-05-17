#pragma once
#include <SDL.h>
#include "GameMap.h"
#include "Agent.h"
#include "Enemy.h"


std::vector<Enemy*> create_enemies();

void handle_camera(SDL_Rect& p_camera, Agent* p_player, int p_LevelWidth, int p_LevelHeight);