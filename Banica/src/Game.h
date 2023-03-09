#pragma once
#include <vector>
#include "raylib.h"
#include <stdint.h>
#include "Renderer.h"
#include "RenderData.h"
#include "GridCell.h"
#include "LevelGeneration.h"
#include "Player.h"
#include "InputHandler.h"

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
        bnc::Player* m_Player;

        std::vector<bnc::GridCell*> m_GridCells; 
        bnc::LevelGenerator* m_LevelGenerator;
        std::vector<Level*> m_Levels;

        bnc::InputHandler* m_InputHandler;

        uint32_t m_CurrentLevel = 0;

        void Update();
        void Configs();
        void VariableInitialization();
    };
}
