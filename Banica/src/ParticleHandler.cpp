#include "ParticleHandler.h"
#include <iostream>

namespace bnc
{
    ParticleHandler::ParticleHandler()
    {

    }

    ParticleHandler::~ParticleHandler()
    {

    }

    void ParticleHandler::UpdateParticles(std::vector<std::shared_ptr<bnc::GridCell>>& gridCells, Player& player, std::vector<std::shared_ptr<bnc::Particle>>& particles, Vector2& position, uint32_t& size)
    {
        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)))
        {
            movementDirection = bnc::RIGHT;
        }

        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        {
            movementDirection = bnc::LEFT;
        }

        if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        {
            movementDirection = bnc::UP;
        }

        if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        {
            movementDirection = bnc::DOWN;
        }

        if(movementDirection == bnc::RIGHT)
        {
            for (size_t i = 0; i < particles.size(); i++)
            {

                if(particles[i]->pariclePosition.x < gridCells[player.GetPlayerPosition() - 1]->position.x + 30)
                {
                    particles.erase(particles.begin() + i);
                }

                particles[i]->pariclePosition.x = position.x;
                position.x -= 0.8;
            }
        }

        if(movementDirection == bnc::LEFT)
        {
            for (size_t i = 0; i < particles.size(); i++)
            {

                if(particles[i]->pariclePosition.x > gridCells[player.GetPlayerPosition() + 1]->position.x + 30)
                {
                    particles.erase(particles.begin() + i);
                }

                particles[i]->pariclePosition.x = position.x;
                position.x += 0.8;
            }
        }

        if(movementDirection == bnc::UP)
        {
            for (size_t i = 0; i < particles.size(); i++)
            {

                if(particles[i]->pariclePosition.y > gridCells[player.GetPlayerPosition()]->position.y + 90)
                {
                    particles.erase(particles.begin() + i);
                }

                particles[i]->pariclePosition.y = position.y;
                position.y += 0.8;
            }
        }

        if(movementDirection == bnc::DOWN)
        {
            for (size_t i = 0; i < particles.size(); i++)
            {

                if(particles[i]->pariclePosition.y < gridCells[player.GetPlayerPosition()]->position.y - 30)
                {
                    particles.erase(particles.begin() + i);
                }

                particles[i]->pariclePosition.y = position.y;
                position.y -= 0.8;
            }
        }
    }
}