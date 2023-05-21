#pragma once
#include <SDL.h>
#include "EventHandler.h"
#include "Agent.h"


void EventHandler::handle_events(Agent* p_agent) {
    //if a key was pressed
    if (m_event.type == SDL_KEYDOWN && m_event.key.repeat == 0)
        switch (m_event.key.keysym.sym) {
        case SDLK_w:
            p_agent->set_moveUp(true);
            break;
        case SDLK_s:
            p_agent->set_moveDown(true);
            break;
        case SDLK_a:
            p_agent->set_moveLeft(true);
            break;
        case SDLK_d:
            p_agent->set_moveRight(true);
            break;
        case SDLK_LSHIFT:
            if (!p_agent->get_timer())
                p_agent->set_timer(SDL_GetTicks());
            break;
        }
    //If a key was released
    else if (m_event.type == SDL_KEYUP && m_event.key.repeat == 0)
        switch (m_event.key.keysym.sym) {
        case SDLK_w:
            p_agent->set_moveUp(false);
            break;
        case SDLK_s:
            p_agent->set_moveDown(false);
            break;
        case SDLK_a:
            p_agent->set_moveLeft(false);
            break;
        case SDLK_d:
            p_agent->set_moveRight(false);
            break;
        }
}