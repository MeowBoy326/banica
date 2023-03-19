#pragma once
#include "raylib.h"
#include "Player.h"
#include "Gate.h"
#include <memory>
#include "Particle.h"
#include "Data.h"

namespace bnc
{
    class InputHandler
    {
    public:
        InputHandler();
        ~InputHandler();

        void HandleInput(std::shared_ptr<bnc::InputHandlerData> inputData);
    private:
        uint32_t m_Timer = 12;
    };
}