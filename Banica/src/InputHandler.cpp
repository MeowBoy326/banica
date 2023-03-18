#include "InputHandler.h"
#include <iostream>

namespace bnc
{
    InputHandler::InputHandler()
    {

    }

    InputHandler::~InputHandler()
    {

    }

    void InputHandler::HandleInput(std::shared_ptr<bnc::Player> player, std::vector<std::shared_ptr<Level>>& levels, uint32_t& curretnLevel, std::vector<std::shared_ptr<bnc::Particle>>& particles, Vector2& position, uint32_t& particleSize)
    {
        std::vector<std::shared_ptr<bnc::GridCell> >& r_Grid = levels[curretnLevel]->GetGridCells();
        std::vector<std::shared_ptr<bnc::Gate> >& r_Gates = levels[curretnLevel]->GetGates();

        //* RIGHT
        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player->GetPlayerPosition() < r_Grid.size() - 1)
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[player->GetPlayerPosition() + 1]->isMovable == true)
                {
                    player->MovePlayerRight();
                    PlaySound(LoadSound("./Banica/sfx/player-movement.wav"));
                }

                for (size_t i = 0; i < levels[curretnLevel]->GetGates().size(); i++)
                {
                    
                    if(r_Grid[r_Gates[i]->GetCellPosition() - 1]->titleType == bnc::PLAYER 
                    && 
                    r_Gates[i]->GetCellPosition() < r_Grid.size()  - levels[curretnLevel]->GetSizeX() - 1 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() + 1]->titleType == bnc::NONE)
                    {
                        player->MovePlayerRight();
                        r_Gates[i]->MoveGateRight();
                        PlaySound(LoadSound("./Banica/sfx/push-gate.wav"));
                    }
                }

                
                m_Timer = 0;
            }

            //* Particles
            if(particles.size() == 1 || particles.size() == 0)
            {
                for (size_t i = 0; i < 5; i++)
                {
                    position.x -= GetRandomValue(0, 10);
                    position.y += GetRandomValue(0, 60);

                    particles.push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{position, particleSize}));

                    position = r_Grid[player->GetPlayerPosition()]->position;
                }
            }
        }

        //* LEFT
        if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && player->GetPlayerPosition() > 0)
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[player->GetPlayerPosition() - 1]->isMovable == true)
                {
                    player->MovePlayerLeft();
                    PlaySound(LoadSound("./Banica/sfx/player-movement.wav"));
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    if(r_Grid[r_Gates[i]->GetCellPosition() + 1]->titleType == bnc::PLAYER 
                    &&
                    r_Gates[i]->GetCellPosition() > levels[curretnLevel]->GetSizeX() 
                    &&
                    r_Grid[r_Gates[i]->GetCellPosition() - 1]->titleType == bnc::NONE)
                    {
                        r_Gates[i]->MoveGateLeft();
                        player->MovePlayerLeft();
                        PlaySound(LoadSound("./Banica/sfx/push-gate.wav"));
                    }
                }

                m_Timer = 0;
            }

            //* Particles
            if(particles.size() == 1 || particles.size() == 0)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    position.x += (GetRandomValue(0, 10)) + 60;
                    position.y += GetRandomValue(0, 60);

                    particles.push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{position, particleSize}));

                    position = Vector2({r_Grid[player->GetPlayerPosition()]->position.x + 60, r_Grid[player->GetPlayerPosition()]->position.y});
                }
            }
        }

        //* UP
        if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && player->GetPlayerPosition() > levels[curretnLevel]->GetSizeX())
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[player->GetPlayerPosition() - levels[curretnLevel]->GetSizeX()]->isMovable == true)
                {
                    player->MovePlayerUp();
                    PlaySound(LoadSound("./Banica/sfx/player-movement.wav"));
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    if(r_Gates[i]->GetCellPosition() > levels[curretnLevel]->GetSizeX() * 2 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() + levels[curretnLevel]->GetSizeX()]->titleType == bnc::PLAYER 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() - levels[curretnLevel]->GetSizeX()]->titleType == bnc::NONE)
                    {
                        r_Gates[i]->MoveGateUp(levels[curretnLevel]->GetSizeX());
                        player->MovePlayerUp();
                        PlaySound(LoadSound("./Banica/sfx/push-gate.wav"));
                    }
                }

                m_Timer = 0;
            }

            //* Particles
            if(particles.size() == 1 || particles.size() == 0)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    position.x += GetRandomValue(0, 60);
                    position.y += GetRandomValue(0, 10) + 60;

                    particles.push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{position, particleSize}));

                    position = Vector2({r_Grid[player->GetPlayerPosition()]->position.x, r_Grid[player->GetPlayerPosition()]->position.y + 60});
                }
            }
        }

        //* DOWN
        if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && player->GetPlayerPosition() < levels[curretnLevel]->GetGridCells().size() - levels[curretnLevel]->GetSizeX())
        {
            if(m_Timer >= 12)
            {

                if(r_Grid[player->GetPlayerPosition() + levels[curretnLevel]->GetSizeX()]->isMovable == true)
                {
                    player->MovePlayerDown();
                    PlaySound(LoadSound("./Banica/sfx/player-movement.wav"));
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    if(r_Gates[i]->GetCellPosition() < r_Grid.size() - levels[curretnLevel]->GetSizeX() * 2 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() - levels[curretnLevel]->GetSizeX()]->titleType == bnc::PLAYER 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() + levels[curretnLevel]->GetSizeX()]->titleType == bnc::NONE)
                    {
                        r_Gates[i]->MoveGateDown(levels[curretnLevel]->GetSizeX());
                        player->MovePlayerDown();
                        PlaySound(LoadSound("./Banica/sfx/push-gate.wav"));
                    }
                }

                m_Timer = 0;
            }

            // //* Particles
            if(particles.size() == 1 || particles.size() == 0)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    position.x += GetRandomValue(0, 60);
                    position.y += GetRandomValue(0, 10);

                    particles.push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{position, particleSize}));

                    position = Vector2({r_Grid[player->GetPlayerPosition()]->position.x, r_Grid[player->GetPlayerPosition()]->position.y});
                }
            }
        }

        m_Timer++;
    }
}