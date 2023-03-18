#pragma once
#include "raylib.h"
#include "Player.h"
#include "Gate.h"
#include <memory>
#include "Particle.h"

namespace bnc
{
    class InputHandler
    {
    public:
        InputHandler();
        ~InputHandler();

        void HandleInput(std::shared_ptr<bnc::Player> player, std::vector<std::shared_ptr<bnc::Level>>& levels, uint32_t& currentLevel, std::vector<std::shared_ptr<bnc::Particle>>& particles, Vector2& position, uint32_t& particleSize);
    private:
        uint32_t m_Timer = 12;
    };
}