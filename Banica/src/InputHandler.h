#pragma once
#include "raylib.h"
#include "Player.h"
#include "Gate.h"
#include <memory>
#include "Particle.h"
#include "Data.h"

namespace bnc
{
    /// @brief This class manages all inputs
    class InputHandler
    {
    public:
        InputHandler();
        ~InputHandler();

        /// @brief This method runs every frame and listens for input
        /// @param inputData It take pointer to a InputHandlerData struct
        /// @see InputHandlerData
        void HandleInput(std::shared_ptr<bnc::InputHandlerData> inputData);
    private:
        uint32_t m_Timer = 12;
    };
}