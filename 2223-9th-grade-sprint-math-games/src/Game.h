#pragma once
#include <vector>
#include "raylib.h"
#include <stdint.h>
#include "Renderer.h"
#include "RenderData.h"
#include "GridCell.h"
#include "GameWorld.h"

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
        bnc::GameWorld* m_GameWorld;

        std::vector<bnc::GridCell*> m_GridCells; 

        void Update();
        void Configs();
        void VariableInitialization();
    };
}
