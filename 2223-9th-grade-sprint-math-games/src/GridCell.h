#pragma once
#include <stdint.h>

namespace bnc
{
    struct GridCell
    {
        bool isPlayerHere = false;
        uint32_t positionX = 0;
        uint32_t positionY = 0;
    };
}