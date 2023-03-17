#pragma once
#include <vector>
#include "Solution.h"
#include "raylib.h"
#include <stdint.h>
#include "Renderer.h"
#include "RenderData.h"
#include "GridCell.h"
#include "LevelGeneration.h"
#include "Player.h"
#include "InputHandler.h"
#include "Gate.h"
#include <memory>
#include "Lamp.h"

namespace bnc
{
    class Game
    {
    public:
        Game(uint32_t width, uint32_t height, const char* title);
        ~Game();
        
        void Run();

    private:
        std::unique_ptr<bnc::Renderer> m_Renderer;
        std::shared_ptr<bnc::RenderData> m_Data;
        std::shared_ptr<bnc::Player> m_Player;

        std::vector<std::shared_ptr<bnc::GridCell>> m_GridCells; 
        std::unique_ptr<LevelGenerator> m_LevelGenerator;

        std::vector<std::shared_ptr<Level>> m_Levels;
        std::vector<std::shared_ptr<Lamp>> m_Lamps;

        std::unique_ptr<bnc::InputHandler> m_InputHandler;

        std::vector<std::shared_ptr<Gate>> m_Gates;

        std::vector<std::shared_ptr<LevelSolution>> m_Solutions;


        uint32_t m_CurrentLevel = 0;

        void Update();
        void Configs();
        void VariableInitialization();
        void ClearLevel();
    };
}
