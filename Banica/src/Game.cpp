#include "Game.h"
#include <iostream>

namespace bnc
{
    Game::Game(uint32_t width, uint32_t height, const char* title)
    {
        Configs();

        InitWindow(width, height, title);
        SetTargetFPS(60);
        
        VariableInitialization();
    }

    Game::~Game()
    {
        CloseWindow();
    }

    void Game::VariableInitialization()
    {
        m_Renderer = std::unique_ptr<bnc::Renderer>(new Renderer);
        m_Data = std::shared_ptr<bnc::RenderData>(new bnc::RenderData);
        m_Player = std::shared_ptr<bnc::Player>( new bnc::Player(&m_GridCells, &m_Levels, &m_CurrentLevel));

        m_LevelGenerator = std::unique_ptr<bnc::LevelGenerator>(new bnc::LevelGenerator(m_Levels, m_GridCells, m_CurrentLevel, m_Player, &m_Gates, &m_Lamps));
        m_LevelGenerator->SetObjects();

        m_Data->levels = &m_Levels;
        m_Data->currentLevel = &m_CurrentLevel;

        m_InputHandler = std::unique_ptr<bnc::InputHandler>(new bnc::InputHandler);
    }

    void Game::Configs()
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    }

    void Game::Update()
    {
        if(IsWindowResized())
        {
            m_GridCells.clear();
            m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
        }

        m_InputHandler->HandleInput(m_Player, m_Levels, m_CurrentLevel);
        m_Player->UpdatePlayer();
        
        for (size_t i = 0; i < m_Gates.size(); i++)
        {
            m_Gates[i]->OnUpdate(&m_GridCells);
        }

        for (size_t i = 0; i < m_Lamps.size(); i++)
        {
            m_Lamps[i]->OnUpdate(m_GridCells);
        }
        
        for (size_t i = 0; i < m_GridCells.size(); i++)
        {
            if(m_GridCells[i]->titleType != bnc::NONE)
            {
                m_GridCells[i]->isMovable = false;
            }
            else
            {
                m_GridCells[i]->isMovable = true;
            }
        }
    }

    void Game::ClearLevel()
    {
        m_GridCells.clear();
        m_Gates.clear();
        m_Lamps.clear();
    }

    void Game::Run()
    {
        while (!WindowShouldClose())
        {
            Update();
            m_Renderer->Render(m_Data);
        }
    }
}