#include "Game.h"

namespace bn
{
    Game::Game(uint32_t width, uint32_t height, const char* title)
    {
        m_ScreenWidth = width;
        m_ScreenHeight = height;

        InitWindow(m_ScreenWidth, m_ScreenHeight, title);
        SetTargetFPS(60);
    }

    Game::~Game()
    {
        CloseWindow();
    }

    void Game::Update()
    {

    }

    void Game::Run()
    {
        while (!WindowShouldClose())
        {
            Update();

            BeginDrawing();

            ClearBackground(RAYWHITE);

            EndDrawing();
        }
        
    }
}