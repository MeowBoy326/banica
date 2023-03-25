#pragma once
#include <stdint.h>
#include "raylib.h"

namespace bnc
{
    /// @brief Enum storing all possible states of a GridCell
    enum
    {
        NONE,
        PLAYER,
        GATE,
        LAMP,
        LAMP_ON,
        LAMP_OFF
    };

    /// @brief This a basic grid cell struct 
    /// It stores the titleType, the position of the cell on the screen and if something can move or be moved on that cell
    struct GridCell
    {
        uint32_t titleType = bnc::NONE;
        Vector2 position;
        bool isMovable = true;
    };
}