#pragma once
#include "Particle.h"
#include <vector>
#include <memory>
#include "GridCell.h"
#include "Player.h"

namespace bnc
{
    class ParticleHandler
    {
    public:
        ParticleHandler();
        ~ParticleHandler();

    void UpdateParticles(std::vector<std::shared_ptr<bnc::GridCell>>& gridCells, Player& player, std::vector<std::shared_ptr<bnc::Particle>>& particles, Vector2& position, uint32_t& size);

    private:
        uint32_t movementDirection = bnc::NONE;
    };
}