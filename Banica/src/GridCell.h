#pragma once
#include <stdint.h>

namespace bnc
{
    struct GridCell
    {
        bool isPlayerHere = false;
        float positionX = 0;
        float positionY = 0;
    };
}