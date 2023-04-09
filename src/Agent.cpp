#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Agent.h"
#include "WindowRender.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

SDL_Texture* Agent::get_texture(){
    return m_texture->get_texture();
}

SDL_Rect* Agent::get_dst(){
    return &m_dst;
}

void Agent::move(){
    //move the agent left or right
    m_dst.x += m_vel_x;

    //If the agent went too far to the left or right
    if (m_dst.x < 0 || m_dst.x + m_diameter > SCREEN_WIDTH)
        //Move back
        m_dst.x -= m_vel_x;

    //Move the agent up or down
    m_dst.y += m_vel_y;

    //If the agent went too far up or down
    if (m_dst.y < 0 || m_dst.y + m_diameter > SCREEN_HEIGHT)
        //Move back
        m_dst.y -= m_vel_y;
}

void Agent::handle_events(SDL_Event& p_event){

    if (p_event.type == SDL_KEYDOWN && p_event.key.repeat == 0)
        //Adjust the velocity
        switch (p_event.key.keysym.sym){
        case SDLK_w:
            m_vel_y -= m_agent_vel;
            break;
        case SDLK_s:
            m_vel_y += m_agent_vel;
            break;
        case SDLK_a:
            m_vel_x -= m_agent_vel;
            break;
        case SDLK_d:
            m_vel_x += m_agent_vel;
            break;
        }
    //If a key was released
	else if (p_event.type == SDL_KEYUP && p_event.key.repeat == 0)
		switch(p_event.key.keysym.sym){
		case SDLK_w:
			m_vel_y += m_agent_vel;
			break;
		case SDLK_s:
			m_vel_y -= m_agent_vel;
			break;
		case SDLK_a:
			m_vel_x += m_agent_vel;
			break;
		case SDLK_d:
            m_vel_x -= m_agent_vel;
			break;
		}
}
