#pragma once
#include "raylib.h"
#include <stdint.h>
#include "Renderer.h"
#include "RenderData.h"

namespace bnc
{
    class Game
    {
    public:
        Game(uint32_t width, uint32_t height, const char* title);
        ~Game();
        
        void Run();

    private:
        bnc::Renderer* m_Renderer;
        bnc::RenderData* m_Data;

        void Update();
        void Configs();
        void VariableInitialization();
    };
}
