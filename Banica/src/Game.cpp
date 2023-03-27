#include "Game.h"
#include <iostream>
#include <string>

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
        UnloadSound(m_ButtonClick);
        UnloadSound(m_CompleteLevel);

        UnloadTexture(m_MainMenuBg);
        UnloadTexture(m_SpriteTexture);
        UnloadFont(m_MainFont);

        UnloadShader(m_BloomShader);
        UnloadShader(m_LightShader);

        CloseWindow();
    }

    void Game::VariableInitialization()
    {
        m_Renderer = std::unique_ptr<bnc::Renderer>(new bnc::Renderer);
        m_Data = std::shared_ptr<bnc::RenderData>(new bnc::RenderData);
        m_Player = std::shared_ptr<bnc::Player>( new bnc::Player(&m_GridCells, &m_Levels, &m_CurrentLevel));

        m_LevelGenerator = std::unique_ptr<bnc::LevelGenerator>(new bnc::LevelGenerator(std::shared_ptr<LevelGenerationData> (new LevelGenerationData{&m_Levels, &m_GridCells, &m_CurrentLevel, m_Player, &m_Gates, &m_Lamps, &m_Solutions, &m_Result})));
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

        std::string dir = GetWorkingDirectory();

        m_PlayerMovement  = LoadSound((dir + std::string("/sfx/player-movement.wav")).c_str());
        m_PlayerPushing = LoadSound((dir + std::string("/sfx/push-gate.wav")).c_str());
        m_ButtonClick = LoadSound((dir + std::string("/sfx/press-button.wav")).c_str());
        m_CompleteLevel = LoadSound((dir + std::string("/sfx/complete-level.wav")).c_str());

        m_BloomShader = LoadShader(0, TextFormat((dir + std::string("/shaders/bloom.fs")).c_str(), 330));
        m_LightShader = LoadShader(0, TextFormat((dir + std::string("/shaders/light.fs")).c_str(), 330));

        m_SpriteTexture = LoadTexture((dir + std::string("/assets/tile-spritesheet.png")).c_str());
        m_MainMenuBg = LoadTexture((dir + std::string("/assets/main-menu-bg.png")).c_str());
        m_LevelSelectBg = LoadTexture((dir + std::string("/assets/level-select-bg.png")).c_str());

        m_MainFont = LoadFont((dir + std::string("/fonts/edit-undo.brk.ttf")).c_str());

        m_Data->bloomShader = m_BloomShader;
        m_Data->spriteTexture = m_SpriteTexture;
        m_Data->lightShader = m_LightShader;
        m_Data->gameState = &m_GameState;
        m_UIData->levels = &m_Levels;
        m_UIData->mainFont = m_MainFont;
        m_UIData->spriteTexture = m_SpriteTexture;
        m_UIData->currentLevel = &m_CurrentLevel;
        m_UIData->gameState = &m_GameState;
        m_UIData->mainMenuBg = m_MainMenuBg;
        m_UIData->LevelSelectMenuBg = m_LevelSelectBg;

        m_UIData->p_Result = &m_Result;

        for (size_t i = 0; i < m_GridCells.size(); i++)
        {
            if(m_GridCells[i]->titleType == bnc::GATE)
            {
                m_UIData->m_FirstGatePosition = m_GridCells[i]->position;
            }
        }
        
    }

    void Game::Configs()
    {
        std::string dir = GetWorkingDirectory();

        InitAudioDevice();

        #ifdef MAKE
            ChangeDirectory((std::string(GetWorkingDirectory()) + std::string("/Banica")).c_str());
        #endif
    }

    void Game::Update()
    {

        if(m_GameState == bnc::TUTORIAL || m_GameState == bnc::GAME)
        {
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
                m_Levels[m_CurrentLevel]->isCompleted = true;
                ClearLevel();
                if(m_GameState == GAME)
                {
                    m_GameState = LEVEL_SELECT;
                }
                else
                {
                    if(m_CurrentLevel == 3)
                    {
                        m_GameState = LEVEL_SELECT;
                    }
                    else
                    {
                        m_CurrentLevel++;
                        m_UIData->skipTutorial = false;
                        m_Player->SetPlayerPosition(56);
                        m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
                        m_LevelGenerator->SetObjects();
                    }
                }
            }

            m_ParticleHandler->UpdateParticles(m_GridCells, *m_Player, m_Particles, m_ParticleNewPosition, m_ParticleSize);

            if(m_UIData->isResetButtonPressed == true)
            {
                PlaySound(m_ButtonClick);
                ClearLevel();
                m_Player->SetPlayerPosition(56);
                m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
                m_LevelGenerator->SetObjects();           
            }

            if(IsKeyPressed(KEY_C))
            {
                m_UIData->skipTutorial = true;
            }
        }
        else if(m_GameState == bnc::LEVEL_SELECT)
        {
            for(uint32_t i = 0; i < 10; i++)
            {
                if(m_UIData->levelSelected[i] == true)
                {
                    PlaySound(m_ButtonClick);
                    if(i == 0)
                    {
                        m_GameState = bnc::TUTORIAL;
                        m_CurrentLevel = 0;

                        ClearLevel();
                        m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
                        m_LevelGenerator->SetObjects();

                    }
                    else
                    {
                        m_GameState = bnc::GAME;
                        m_CurrentLevel = i;
                        
                        ClearLevel();
                        m_LevelGenerator->GenerateLevel(m_Levels, m_CurrentLevel);
                        m_LevelGenerator->SetObjects();
                    }
                }
            }
        }
        else
        {
            if(m_UIData->isPlayButtonPressed)
            {
                m_GameState = bnc::LEVEL_SELECT;
                PlaySound(m_ButtonClick);
            }
        }

        if(m_UIData->isBackButtonPressed)
        {
            switch(m_GameState)
            {
                case LEVEL_SELECT:
                    m_GameState = MAIN_MENU;
                    break;
                case TUTORIAL:
                case GAME:
                    m_GameState = LEVEL_SELECT;
                    break;
            }
            PlaySound(m_ButtonClick);
        }
        m_UIData->isBackButtonPressed = false;
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
        while (!(WindowShouldClose() || (m_UIData->isQuitButtonPressed)))
        {
            Update();

            BeginDrawing();
            m_Renderer->Render(m_Data);
            m_UIRenderer->RenderUI(m_UIData);

            EndDrawing();
        }
    }
}