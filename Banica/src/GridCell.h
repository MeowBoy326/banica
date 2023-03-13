#pragma once
#include <stdint.h>
#include "raylib.h"

namespace bnc
{
    enum
    {
        NONE,
        PLAYER,
        GATE
    };

    struct GridCell
    {
        uint32_t titleType = bnc::NONE;
        Vector2 position;
        bool isMovable = true;
    };
}