#pragma once
#include <SDL.h>
#include <vector>
#include "Agent.h"
#include "GameMap.h"


Agent::Agent() {
    m_vel = 6;
}

void Agent::move() {
    //Move the agent left or right
    if (m_moveLeft)
        m_dotCenter.x -= m_vel;
    if (m_moveRight)
        m_dotCenter.x += m_vel;

    //If the agent went too far to the left
    if (m_dotCenter.x < m_radius)
        //Move the agent to the left edge
        m_dotCenter.x = m_radius;

    //If the agent went too far to the right
    if (m_dotCenter.x > LEVEL_WIDTH * 64 - m_radius)
        //Move the agent to the right edge
        m_dotCenter.x = LEVEL_WIDTH * 64 - m_radius;

    //Move the agent up or down
    if (m_moveUp)
        m_dotCenter.y -= m_vel;
    if (m_moveDown)
        m_dotCenter.y += m_vel;

    //If the agent went too far up
    if (m_dotCenter.y < m_radius)
        //Move the agent to the upper edge
        m_dotCenter.y = m_radius;

    //If the agent went too far down
    if (m_dotCenter.y > LEVEL_HEIGHT * 64 - m_radius)
        //Move the agent to the lower edge
        m_dotCenter.y = LEVEL_HEIGHT * 64 - m_radius;
}
