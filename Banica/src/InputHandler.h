#pragma once
#include "raylib.h"
#include "Player.h"
#include "Gate.h"
#include <memory>

namespace bnc
{
    class InputHandler
    {
    public:
        InputHandler();
        ~InputHandler();

        void HandleInput(std::shared_ptr<bnc::Player> player, std::vector<std::shared_ptr<bnc::Level>>& levels, uint32_t& currentLevel);

    private:
        uint32_t m_Timer = 12;
    };
}