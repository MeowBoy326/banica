#pragma once
#include "raylib.h"
#include "stdint.h"
#include "Renderer.h"
#include "RenderData.h"

namespace bn
{
    class Game
    {
    public:
        Game(uint32_t width, uint32_t height, const char* title);
        ~Game();
        
        void Run();

    private:
        bn::Renderer* m_Renderer;
        bn::RenderData* m_Data = new bn::RenderData;      

        void Update();
        void Configs();
        void VariableInitialization();
    };
}
