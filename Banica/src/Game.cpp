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
        UnloadSound(m_PlayerMovement);
        UnloadSound(m_PlayerPushing);
        CloseWindow();
    }

    void Game::VariableInitialization()
    {
        m_Renderer = std::unique_ptr<bnc::Renderer>(new bnc::Renderer);
        m_Data = std::shared_ptr<bnc::RenderData>(new bnc::RenderData);
        m_Player = std::shared_ptr<bnc::Player>( new bnc::Player(&m_GridCells, &m_Levels, &m_CurrentLevel));

        m_LevelGenerator = std::unique_ptr<bnc::LevelGenerator>(new bnc::LevelGenerator(std::shared_ptr<LevelGenerationData> (new LevelGenerationData{&m_Levels, &m_GridCells, &m_CurrentLevel, m_Player, &m_Gates, &m_Lamps, &m_Solutions})));
        m_LevelGenerator->SetObjects();

        m_Data->levels = &m_Levels;
        m_Data->currentLevel = &m_CurrentLevel;
        m_Data->particles = &m_Particles;


        m_InputHandler = std::unique_ptr<bnc::InputHandler>(new bnc::InputHandler);

        m_ParticleHandler = std::unique_ptr<bnc::ParticleHandler>(new bnc::ParticleHandler());

        m_UIRenderer = std::unique_ptr<bnc::UIRenderer>(new bnc::UIRenderer);
        m_UIData = std::shared_ptr<bnc::UIData>(new bnc::UIData);

        m_ParticleNewPosition = m_GridCells[m_Player->GetPlayerPosition()]->position;
        m_ParticleSize = GetRandomValue(10, 15);

        m_PlayerMovement  = LoadSound("./Banica/sfx/player-movement.wav");
        m_PlayerPushing = LoadSound("./Banica/sfx/push-gate.wav");
        m_ButtonClick = LoadSound("./Banica/sfx/press-button.wav");
        m_CompleteLevel = LoadSound("./Banica/sfx/complete-level.wav");
    }

    void Game::Configs()
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitAudioDevice();
    }

    void Game::Update()
    {
        if(IsWindowResized())
        {
            m_GridCells.clear();
            m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
        }

        m_InputHandler->HandleInput(std::shared_ptr<bnc::InputHandlerData>(new InputHandlerData{m_Player, &m_Levels, &m_CurrentLevel, &m_Particles, &m_ParticleNewPosition, &m_ParticleSize, m_PlayerMovement, m_PlayerPushing}));
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

        uint32_t completed = 0;

        for (size_t i = 0; i < m_Gates.size(); i++)
        {
            for (size_t j = 0; j < m_Solutions.size(); j++)
            {
                if(m_Gates[i]->GetCellPosition() == m_Solutions[j]->solutionPosition && m_Gates[i]->GetType() == m_Solutions[j]->gateType)
                {
                    completed++;
                    break;
                }
            }

        }
        
        if(completed == m_Solutions.size())
        {
            PlaySound(m_CompleteLevel);
            ClearLevel();
            m_CurrentLevel++;
            m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
            m_LevelGenerator->SetObjects();
        }

        m_ParticleHandler->UpdateParticles(m_GridCells, *m_Player, m_Particles, m_ParticleNewPosition, m_ParticleSize);

        if(*m_UIData->isResetButtonPressed == true)
        {
            PlaySound(m_ButtonClick);
            ClearLevel();
            m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
            m_LevelGenerator->SetObjects();           
        }
    }

    void Game::ClearLevel()
    {
        m_GridCells.clear();
        m_Gates.clear();
        m_Particles.clear();
        m_Solutions.clear();
        m_Lamps.clear();
    }

    void Game::Run()
    {
        while (!WindowShouldClose())
        {
            Update();

            BeginDrawing();
            m_Renderer->Render(m_Data);
            m_UIRenderer->RenderUI(m_UIData);

            EndDrawing();
        }
    }
}