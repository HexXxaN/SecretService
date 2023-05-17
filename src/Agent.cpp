#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Agent.h"
#include "WindowRender.h"
#include "GameMap.h"


SDL_Rect* Agent::get_dst() {
    return &m_dst;
}

Point Agent::get_dotCenter()
{
    return m_dotCenter;
}

short int Agent::get_diameter() {
    return m_Diameter;
}

void Agent::move(std::vector<SDL_Rect> p_colliders) {
    SDL_Rect tmp = m_dst;
    //Move the agent left or right
    if (m_moveLeft)
        m_dst.x -= m_agent_vel;
    if (m_moveRight)
        m_dst.x += m_agent_vel;

    //If the agent went too far to the left
    if (m_dst.x < 0)
        //Move the agent to the left edge
        m_dst.x = 0;

    //If the agent went too far to the right
    if (m_dst.x > LEVEL_WIDTH * 64 - m_Diameter)
        //Move the agent to the right edge
        m_dst.x = LEVEL_WIDTH * 64 - m_Diameter;

    //Move the agent up or down
    if (m_moveUp)
        m_dst.y -= m_agent_vel;
    if (m_moveDown)
        m_dst.y += m_agent_vel;

    //If the agent went too far up
    if (m_dst.y < 0)
        //Move the agent to the upper edge
        m_dst.y = 0;

    //If the agent went too far down
    if (m_dst.y > LEVEL_HEIGHT * 64 - m_Diameter)
        //Move the agent to the lower edge
        m_dst.y = LEVEL_HEIGHT * 64 - m_Diameter;


    //__________COLLISION DETECTION__________
    m_dotCenter.x = m_dst.x + (0.5 + m_Diameter / 2) + 1;
    m_dotCenter.y = m_dst.y + (0.5 + m_Diameter / 2) + 1;
    int closestX, closestY;

    for (auto &obsticle : p_colliders) {
        //Find the closest x coordinate of the obsticle
        if (m_dotCenter.x < obsticle.x)
            closestX = obsticle.x;
        else if (m_dotCenter.x > obsticle.x + obsticle.w)
            closestX = obsticle.x + obsticle.w;
        else
            closestX = m_dotCenter.x;

        //Find the closest y coordinate of the obsticle
        if (m_dotCenter.y < obsticle.y)
            closestY = obsticle.y;
        else if (m_dotCenter.y > obsticle.y + obsticle.h)
            closestY = obsticle.y + obsticle.h;
        else
            closestY = m_dotCenter.y;

        //Checking if the closest point is inside the circle from Pythagorean theorem
        int deltaX = closestX - m_dotCenter.x;
        int deltaY = closestY - m_dotCenter.y;
        if (deltaX * deltaX + deltaY * deltaY < m_Diameter * m_Diameter / 4) {
            if (tmp.x <= obsticle.x - m_Diameter && tmp.y >= obsticle.y - m_Diameter && tmp.y <= obsticle.y + obsticle.h)
                m_dst.x = obsticle.x - m_Diameter;
            else if (tmp.x >= obsticle.x + obsticle.w && tmp.y >= obsticle.y - m_Diameter && tmp.y <= obsticle.y + obsticle.h)
                m_dst.x = obsticle.x + obsticle.w;
            else if (tmp.y <= obsticle.y && tmp.x >= obsticle.x - m_Diameter && tmp.x <= obsticle.x + obsticle.w)
                m_dst.y = obsticle.y - m_Diameter;
            else
                m_dst.y = obsticle.y + obsticle.h;
        }
    }
}

void Agent::handle_events(SDL_Event& p_event) {

    if (p_event.type == SDL_KEYDOWN && p_event.key.repeat == 0)
        //Adjust the velocity
        switch (p_event.key.keysym.sym) {
        case SDLK_w:
            m_moveUp = true;
            break;
        case SDLK_s:
            m_moveDown = true;
            break;
        case SDLK_a:
            m_moveLeft = true;
            break;
        case SDLK_d :
            m_moveRight = true;
            break;
        case SDLK_LSHIFT:
            if (!m_timer)
                m_timer = SDL_GetTicks();
            break;
        }
    //If a key was released
    else if (p_event.type == SDL_KEYUP && p_event.key.repeat == 0)
        switch (p_event.key.keysym.sym) {
        case SDLK_w:
            m_moveUp = false;
            break;
        case SDLK_s:
            m_moveDown = false;
            break;
        case SDLK_a:
            m_moveLeft = false;
            break;
        case SDLK_d:
            m_moveRight = false;
            break;
        }
}
