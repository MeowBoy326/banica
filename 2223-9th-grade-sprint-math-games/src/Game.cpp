#include "Game.h"
#include "iostream"

namespace bn
{
    Game::Game(uint32_t width, uint32_t height, const char* title)
    {
        InitWindow(width, height, title);
        SetTargetFPS(60);

        m_Renderer = new bn::Renderer();

        m_Data->cubePositionX = 0;
        m_Data->cubePositionY = height;
    }

    Game::~Game()
    {
        CloseWindow();
        delete m_Renderer;
        delete m_Data;
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

            BeginDrawing();
            ClearBackground(RAYWHITE);

            m_Renderer->Render(m_Data);

            EndDrawing();
        }
        
    }
}