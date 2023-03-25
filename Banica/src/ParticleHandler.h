#pragma once
#include "Particle.h"
#include <vector>
#include <memory>
#include "GridCell.h"
#include "Player.h"

namespace bnc
{
    /// @brief This class is responsible for handling all particle on the screen
    class ParticleHandler
    {
    public:
        ParticleHandler();
        ~ParticleHandler();

    /// @brief Runs every frame updating the particles
    /// @param gridCells Reference to a vector storing the grid
    /// @param player Reference to an instance of the player
    /// @param particles Reference to a vector storing all particles
    /// @param position Referece to a Vector2 storing the position of the particle
    /// @param size Reference to an unsiged int storing the size of the particle
    void UpdateParticles(std::vector<std::shared_ptr<bnc::GridCell>>& gridCells, Player& player, std::vector<std::shared_ptr<bnc::Particle>>& particles, Vector2& position, uint32_t& size);

    private:
        uint32_t movementDirection = bnc::NONE;
    };
}