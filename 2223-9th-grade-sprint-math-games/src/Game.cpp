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
    }

    void Game::VariableInitialization()
    {
        m_Renderer = new bnc::Renderer();
        m_Data = new bnc::RenderData;
        m_GameWorld = new bnc::GameWorld(&m_GridCells);

        m_Data->gridCells = &m_GridCells;
    }

    void Game::Configs()
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    }

    void Game::Update()
    {
        std::cout << m_GridCells.size() << std::endl;
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