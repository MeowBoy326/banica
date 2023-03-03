#pragma once
#include "raylib.h"
#include "stdint.h"

namespace bn
{
    class Game
    {
    public:
        Game(uint32_t width, uint32_t height, const char* title);
        ~Game();
        
        void Run();

    private:
        uint32_t m_ScreenWidth;
        uint32_t m_ScreenHeight;

        void Update();
    };
} 
