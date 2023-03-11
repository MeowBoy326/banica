#pragma once
#include "raylib.h"
#include "Player.h"

namespace bnc
{
    class InputHandler
    {
    public:
        InputHandler();
        ~InputHandler();

        void HandleInput(bnc::Player* player, std::vector<bnc::Level*>& levels, uint32_t& currentLevel);

    private:
        uint32_t m_Timer = 12;
    };
}