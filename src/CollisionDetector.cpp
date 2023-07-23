#pragma once
#include <SDL.h>
#include <cmath>
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

void CollisionDetector::move_player(Agent* p_player) {
    Point prev = p_player->get_dotCenter();
    p_player->move();
    this->detect_collisions(p_player, prev);
}

void CollisionDetector::move_enemies(std::vector<Enemy*> p_enemies) {
    for (auto& enemy : p_enemies) {
        Point prev = enemy->get_dotCenter();

        if (enemy->get_Timer()->get_current_time() - enemy->get_Timer()->get_start() >= enemy->get_movementTime())
            enemy->generate_movementTime();

        enemy->move();

        this->detect_collisions(enemy, prev);

        bool isOnPavement = false;
        Point currentPosition = enemy->get_dotCenter();

        for (auto& walkingSurface : m_walkingSurfaces) {
            if ((currentPosition.x >= walkingSurface.x && currentPosition.x <= walkingSurface.x + walkingSurface.w) &&
                (currentPosition.y >= walkingSurface.y && currentPosition.y <= walkingSurface.y + walkingSurface.h)) {
                isOnPavement = true;
                break;
            }
        }

        if (!isOnPavement)
            enemy->set_dotCenter(prev);
    }
}

void CollisionDetector::detect_player(Agent* p_player, std::vector<Enemy*> p_enemies) {

    if (p_player->can_be_detected()) {
        Point playerPos = p_player->get_dotCenter();

        for (auto& enemy : p_enemies) {
            if (enemy->detect_player(playerPos)) {

                Point enemyPos = enemy->get_dotCenter();
                SDL_Rect detectionRect;

                if (playerPos.x < enemyPos.x) {
                    detectionRect.x = playerPos.x;
                    detectionRect.w = enemyPos.x - playerPos.x;
                }
                else {
                    detectionRect.x = enemyPos.x;
                    detectionRect.w = playerPos.x - enemyPos.x;
                }

                if (playerPos.y < enemyPos.y) {
                    detectionRect.y = playerPos.y;
                    detectionRect.h = enemyPos.y - playerPos.y;
                }
                else {
                    detectionRect.y = enemyPos.y;
                    detectionRect.h = playerPos.y - enemyPos.y;
                }

                bool obsticleBetweenEntities = false;

                for (auto& collider : m_colliders) {
                    // If there's an object between player and enemy, the enemy won't detect the player
                    if (detectionRect.x > collider.x - detectionRect.w && detectionRect.x < collider.x + collider.w &&
                        detectionRect.y > collider.y - detectionRect.h && detectionRect.y < collider.y + collider.h) {
                        obsticleBetweenEntities = true;
                        break;
                    }
                }

                // If there's no obsticle between player and enemy, the enemies get the player position
                if (!obsticleBetweenEntities) {
                    std::cout << "Player detected!\n";
                    Enemy::set_playerPos(playerPos);
                }
            }
        }
    }
}

void CollisionDetector::detect_collisions(MovableCircularObject* p_entity, Point p_prev) {

    unsigned short int closestX, closestY;
    unsigned short int radius = p_entity->get_radius();
    Point dotCenter = p_entity->get_dotCenter();

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
            if (p_prev.x <= obsticle.x - radius / 2 && p_prev.y >= obsticle.y - radius && p_prev.y <= obsticle.y + obsticle.h + radius)
                //Move to the left edge
                dotCenter.x = obsticle.x - radius;
            //If the player was to the right of an obsticle
            else if (p_prev.x >= obsticle.x + obsticle.w + radius && p_prev.y >= obsticle.y - radius && p_prev.y <= obsticle.y + obsticle.h + radius)
                //Move to the right edge
                dotCenter.x = obsticle.x + obsticle.w + radius;
            //If player was on the top edge of an obsticle
            else if (p_prev.y <= obsticle.y - radius && p_prev.x >= obsticle.x - radius && p_prev.x <= obsticle.x + obsticle.w + radius)
                //Move to the top edge
                dotCenter.y = obsticle.y - radius;
            else
                //Move to the bottom edge
                dotCenter.y = obsticle.y + obsticle.h + radius;

            p_entity->set_dotCenter(dotCenter);
        }
    }
}

