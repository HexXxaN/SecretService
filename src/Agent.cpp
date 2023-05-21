#pragma once
#include <SDL.h>
#include <vector>
#include "Agent.h"
#include "Collider.h"
#include "GameMap.h"


void Agent::move(Collider* p_Colliders) {
    Point tmp = m_dotCenter;
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


    //__________COLLISION DETECTION__________
    //int closestX, closestY;

    //for (auto &obsticle : p_colliders) {
    //    //Find the closest x coordinate of the obsticle
    //    if (m_dotCenter.x < obsticle.x)
    //        closestX = obsticle.x;
    //    else if (m_dotCenter.x > obsticle.x + obsticle.w)
    //        closestX = obsticle.x + obsticle.w;
    //    else
    //        closestX = m_dotCenter.x;

    //    //Find the closest y coordinate of the obsticle
    //    if (m_dotCenter.y < obsticle.y)
    //        closestY = obsticle.y;
    //    else if (m_dotCenter.y > obsticle.y + obsticle.h)
    //        closestY = obsticle.y + obsticle.h;
    //    else
    //        closestY = m_dotCenter.y;

    //    //Checking if the closest point is inside the circle from Pythagorean theorem
    //    int deltaX = closestX - m_dotCenter.x;
    //    int deltaY = closestY - m_dotCenter.y;
    //    if (deltaX * deltaX + deltaY * deltaY < m_Diameter * m_Diameter / 4) {
    //        if (tmp.x <= obsticle.x - m_Diameter && tmp.y >= obsticle.y - m_Diameter && tmp.y <= obsticle.y + obsticle.h)
    //            m_dst.x = obsticle.x - m_Diameter;
    //        else if (tmp.x >= obsticle.x + obsticle.w && tmp.y >= obsticle.y - m_Diameter && tmp.y <= obsticle.y + obsticle.h)
    //            m_dst.x = obsticle.x + obsticle.w;
    //        else if (tmp.y <= obsticle.y && tmp.x >= obsticle.x - m_Diameter && tmp.x <= obsticle.x + obsticle.w)
    //            m_dst.y = obsticle.y - m_Diameter;
    //        else
    //            m_dst.y = obsticle.y + obsticle.h;
    //    }
    //}
}
