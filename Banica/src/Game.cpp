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
        delete m_Renderer;
        delete m_Data;
        delete m_Player;
    }

    void Game::VariableInitialization()
    {
        m_Renderer = new bnc::Renderer;
        m_Data = new bnc::RenderData;
        m_Player = new bnc::Player(&m_GridCells, &m_Levels, &m_CurrentLevel);

        m_LevelGenerator = new bnc::LevelGenerator(m_Levels, m_GridCells, m_CurrentLevel, *m_Player, &m_Gates);

        m_Data->levels = &m_Levels;
        m_Data->currentLevel = &m_CurrentLevel;

        m_InputHandler = new bnc::InputHandler;
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