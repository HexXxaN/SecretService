#pragma once
#include <SDL.h>
#include "CollisionDetector.h"
#include "Agent.h"

void CollisionDetector::set_colliders(GameMap* p_GameMap) {
    std::vector<StaticRectangularObject*> mapColliders = p_GameMap->get_StaticRectangularObjects();
    std::vector<Building*> buildings = p_GameMap->get_Buildings();

    SDL_Rect rect;

    for (auto& collider : mapColliders) {
        rect.x = collider->get_origin().x * 64;
        rect.y = collider->get_origin().y * 64;
        rect.w = collider->get_width() * 64;
        rect.h = collider->get_height() * 64;

        if (collider->get_type() == texture_type::wall)
            m_colliders.push_back(rect);
        else
            m_walkingSurfaces.push_back(rect);
    }

    for (auto& building : buildings) {
        std::vector<StaticRectangularObject*> components = building->get_components();
        for (auto& component : components) {
            rect.x = (component->get_origin().x + building->get_origin().x) * 64;
            rect.y = (component->get_origin().y + building->get_origin().y) * 64;
            rect.w = component->get_width() * 64;
            rect.h = component->get_height() * 64;

            if (component->get_type() == texture_type::wall)
                m_colliders.push_back(rect);
            else
                m_walkingSurfaces.push_back(rect);
        }
    }
}

void CollisionDetector::manage_collisions(Agent* p_player) {
    Point tmp = p_player->get_dotCenter();

    p_player->move();

    unsigned short int closestX, closestY;
    unsigned short int radius = p_player->get_radius();

    Point dotCenter = p_player->get_dotCenter();

    for (auto& obsticle : m_colliders) {
        //Find the closest x coordinate of the obsticle
        if (dotCenter.x < obsticle.x)
            closestX = obsticle.x;
        else if (dotCenter.x > obsticle.x + obsticle.w)
            closestX = obsticle.x + obsticle.w;
        else
            closestX = dotCenter.x;

        //Find the closest y coordinate of the obsticle
        if (dotCenter.y < obsticle.y)
            closestY = obsticle.y;
        else if (dotCenter.y > obsticle.y + obsticle.h)
            closestY = obsticle.y + obsticle.h;
        else
            closestY = dotCenter.y;

        //Checking if the closest point is inside the circle from Pythagorean theorem
        int deltaX = closestX - dotCenter.x;
        int deltaY = closestY - dotCenter.y;
        //If collision occured 
        if (deltaX * deltaX + deltaY * deltaY < radius * radius) {
            //If the player was to the left of an obsticle
            if (tmp.x <= obsticle.x - radius / 2 && tmp.y >= obsticle.y - radius && tmp.y <= obsticle.y + obsticle.h + radius)
                //Move to the left edge
                dotCenter.x = obsticle.x - radius;
            //If the player was to the right of an obsticle
            else if (tmp.x >= obsticle.x + obsticle.w + radius && tmp.y >= obsticle.y - radius && tmp.y <= obsticle.y + obsticle.h + radius)
                //Move to the right edge
                dotCenter.x = obsticle.x + obsticle.w + radius;
            //If player was on the top edge of an obsticle
            else if (tmp.y <= obsticle.y - radius && tmp.x >= obsticle.x - radius && tmp.x <= obsticle.x + obsticle.w + radius )
                //Move to the top edge
                dotCenter.y = obsticle.y - radius;
            else
                //Move to the bottom edge
                dotCenter.y = obsticle.y + obsticle.h + radius;
        }
        p_player->set_dotCenter(dotCenter);
    }
}

