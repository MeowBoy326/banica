#include "Game.h"
#include <iostream>

namespace bnc
{
    Game::Game(uint32_t width, uint32_t height, const char* title)
    {
        Configs();

        InitWindow(width, height, title);
        
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
        m_Data = new bnc::RenderData();

        m_Data->cubePositionX = 0;
        m_Data->cubePositionY = GetScreenHeight();
    }

    void Game::Configs()
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        SetTargetFPS(60);
    }

    void Game::Update()
    {
        m_Data->cubePositionX += 5;
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