#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Agent.h"
#include "WindowRender.h"

#define SCREEN_WIDTH 20*64
#define SCREEN_HEIGHT 10*64

SDL_Rect* Agent::get_dst() {
    return &m_dst;
}

void Agent::move(std::vector<SDL_Rect> p_colliders) {
    //Move the agent left or right
    m_dst.x += m_vel_x;

    //If the agent went too far to the left
    if (m_dst.x < 0)
        //Move the agent to the left edge
        m_dst.x = 0;

    //If the agent went too far to the right
    if (m_dst.x > SCREEN_WIDTH - m_diameter)
        //Move the agent to the right edge
        m_dst.x = SCREEN_WIDTH - m_diameter;

    //Move the agent up or down
    m_dst.y += m_vel_y;

    //If the agent went too far up
    if (m_dst.y < 0)
        //Move the agent to the upper edge
        m_dst.y = 0;

    //If the agent went too far down
    if (m_dst.y > SCREEN_HEIGHT - m_diameter)
        //Move the agent to the lower edge
        m_dst.y = SCREEN_HEIGHT - m_diameter;

    //TODO
    //__________COLLISION DETECTION__________
    //int dotCenterX = m_dst.x + (int)(m_diameter / 2) + 1;
    //int dotCenterY = m_dst.y + (int)(m_diameter / 2) + 1;
    //int closestX, closestY;

    for (auto& obsticle : p_colliders) {
        bool collision = true;
        //Checking if there is separation between objects
        if (m_dst.x + m_dst.w <= obsticle.x)
            collision = false;
        else if (m_dst.x >= obsticle.x + obsticle.w)
            collision = false;
        else if (m_dst.y >= obsticle.y + obsticle.h)
            collision = false;
        else if (m_dst.y + m_dst.h <= obsticle.y)
            collision = false;

        //If there is no separation then adjust the position of the agent
        if (collision) {


            //________THIS WORKS, BUT NOT AS GOOD AS I WISH____________
            //if (m_vel_x > 0 && !m_vel_y)
            //    m_dst.x = obsticle.x - m_diameter;
            //if (m_vel_x < 0 && !m_vel_y)
            //    m_dst.x = obsticle.x + obsticle.w;

            //if (m_vel_y > 0 && !m_vel_x)
            //    m_dst.y = obsticle.y - m_diameter;
            //if (m_vel_y < 0 && !m_vel_x)
            //    m_dst.y = obsticle.y + obsticle.h;

            //if (m_vel_x && m_vel_y) {
            //    m_dst.x -= m_vel_x;
            //    m_dst.y -= m_vel_y;
            //}
            //_____________________________________________________________
        }
        //__________________________________________
        //Find the closest x coordinate of the obsticle
        //if (dotCenterX < obsticle.x)
        //    closestX = obsticle.x;
        //else if (dotCenterX > obsticle.x + obsticle.w)
        //    closestX = obsticle.x + obsticle.w;
        //else
        //    closestX = dotCenterX;

        ////Find the closest y coordinate of the obsticle
        //if (dotCenterY < obsticle.y)
        //    closestY = obsticle.y;
        //else if (dotCenterY > obsticle.y + obsticle.h)
        //    closestY = obsticle.y + obsticle.h;
        //else
        //    closestY = dotCenterY;

        ////Checking if the closest point is inside the circle from Pythagorean theorem
        //int deltaX = closestX - dotCenterX;
        //int deltaY = closestY - dotCenterY;

        //if (deltaX * deltaX + deltaY * deltaY < m_diameter * m_diameter / 4) {
        //    //If the dot is moving form left to right
        //    if (m_vel_x > 0)
        //        //Move the dot to the left edge of the obsticle
        //        m_dst.x = obsticle.x - m_diameter;
        //    //If the dot is moving form right to left
        //    else if(m_vel_x < 0)
        //        m_dst.x = obsticle.x + obsticle.w;
        //    //If the dot is moving from top to bottom
        //    else if (m_vel_y > 0)
        //        //Move the dot to the upper edge of the obsticle
        //        m_dst.y = obsticle.y - m_diameter;
        //    //If the dot is moving from bottom to top
        //    else if (m_vel_y < 0)
        //        m_dst.y = obsticle.y + obsticle.h;
        //    break;
        //}
    }
}

void Agent::handle_events(SDL_Event& p_event){

    if (p_event.type == SDL_KEYDOWN && p_event.key.repeat == 0)
        //Adjust the velocity
        switch (p_event.key.keysym.sym) {
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
		switch(p_event.key.keysym.sym) {
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
