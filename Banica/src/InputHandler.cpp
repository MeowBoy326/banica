#include "InputHandler.h"
#include <iostream>
#include "Data.h"

namespace bnc
{
    InputHandler::InputHandler()
    {

    }

    InputHandler::~InputHandler()
    {

    }

    void InputHandler::HandleInput(std::shared_ptr<bnc::InputHandlerData> inputData)
    {
        std::vector<std::shared_ptr<bnc::GridCell>>& r_Grid = inputData->levels->operator[](*inputData->currentLevel)->GetGridCells();
        std::vector<std::shared_ptr<bnc::Gate>>& r_Gates = inputData->levels->operator[](*inputData->currentLevel)->GetGates();

        //* RIGHT
        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && inputData->player->GetPlayerPosition() < r_Grid.size() - 1)
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[inputData->player->GetPlayerPosition() + 1]->isMovable == true)
                {
                    inputData->player->MovePlayerRight();
                    PlaySound(inputData->playerMovement);
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    
                    if(r_Grid[r_Gates[i]->GetCellPosition() - 1]->titleType == bnc::PLAYER 
                    && 
                    r_Gates[i]->GetCellPosition() < r_Grid.size()  - inputData->levels->operator[](*inputData->currentLevel)->GetSizeX() - 1 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() + 1]->titleType == bnc::NONE)
                    {
                        inputData->player->MovePlayerRight();
                        r_Gates[i]->MoveGateRight();
                        PlaySound(inputData->playerPushing);
                    }
                }

                
                m_Timer = 0;
            }

            //* Particles
            if(inputData->particles->size() == 1 || inputData->particles->size() == 0)
            {
                for (size_t i = 0; i < 5; i++)
                {
                    inputData->position->x -= GetRandomValue(0, 10);
                    inputData->position->y += GetRandomValue(0, 60);

                    inputData->particles->push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{*inputData->position, *inputData->particleSize}));

                    *inputData->position = r_Grid[inputData->player->GetPlayerPosition()]->position;
                }
            }
        }

        //* LEFT
        if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && inputData->player->GetPlayerPosition() > 0)
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[inputData->player->GetPlayerPosition() - 1]->isMovable == true)
                {
                    inputData->player->MovePlayerLeft();
                    PlaySound(inputData->playerMovement);
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    if(r_Grid[r_Gates[i]->GetCellPosition() + 1]->titleType == bnc::PLAYER 
                    &&
                    r_Gates[i]->GetCellPosition() > inputData->levels->operator[](*inputData->currentLevel)->GetSizeX() 
                    &&
                    r_Grid[r_Gates[i]->GetCellPosition() - 1]->titleType == bnc::NONE)
                    {
                        r_Gates[i]->MoveGateLeft();
                        inputData->player->MovePlayerLeft();
                        PlaySound(inputData->playerPushing);
                    }
                }

                m_Timer = 0;
            }

            //* Particles
            if(inputData->particles->size() == 1 || inputData->particles->size() == 0)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    inputData->position->x += (GetRandomValue(0, 10)) + 60;
                    inputData->position->y += GetRandomValue(0, 60);

                    inputData->particles->push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{*inputData->position, *inputData->particleSize}));

                    *inputData->position = Vector2({r_Grid[inputData->player->GetPlayerPosition()]->position.x + 60, r_Grid[inputData->player->GetPlayerPosition()]->position.y});
                }
            }
        }

        //* UP
        if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && inputData->player->GetPlayerPosition() >= inputData->levels->operator[](*inputData->currentLevel)->GetSizeX())
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[inputData->player->GetPlayerPosition() - inputData->levels->operator[](*inputData->currentLevel)->GetSizeX()]->isMovable == true)
                {
                    inputData->player->MovePlayerUp();
                    PlaySound(inputData->playerMovement);
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    if(r_Gates[i]->GetCellPosition() > inputData->levels->operator[](*inputData->currentLevel)->GetSizeX() * 2 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() + inputData->levels->operator[](*inputData->currentLevel)->GetSizeX()]->titleType == bnc::PLAYER 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() - inputData->levels->operator[](*inputData->currentLevel)->GetSizeX()]->titleType == bnc::NONE)
                    {
                        r_Gates[i]->MoveGateUp(inputData->levels->operator[](*inputData->currentLevel)->GetSizeX());
                        inputData->player->MovePlayerUp();
                        PlaySound(inputData->playerPushing);
                    }
                }

                m_Timer = 0;
            }

            //* Particles
            if(inputData->particles->size() == 1 || inputData->particles->size() == 0)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    inputData->position->x += GetRandomValue(0, 60);
                    inputData->position->y += GetRandomValue(0, 10) + 60;

                    inputData->particles->push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{*inputData->position, *inputData->particleSize}));

                    *inputData->position = Vector2({r_Grid[inputData->player->GetPlayerPosition()]->position.x, r_Grid[inputData->player->GetPlayerPosition()]->position.y + 60});
                }
            }
        }

        //* DOWN
        if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && inputData->player->GetPlayerPosition() < inputData->levels->operator[](*inputData->currentLevel)->GetGridCells().size() - inputData->levels->operator[](*inputData->currentLevel)->GetSizeX())
        {
            if(m_Timer >= 12)
            {

                if(r_Grid[inputData->player->GetPlayerPosition() + inputData->levels->operator[](*inputData->currentLevel)->GetSizeX()]->isMovable == true)
                {
                    inputData->player->MovePlayerDown();
                    PlaySound(inputData->playerMovement);
                }

                for (size_t i = 0; i < r_Gates.size(); i++)
                {
                    if(r_Gates[i]->GetCellPosition() < r_Grid.size() - inputData->levels->operator[](*inputData->currentLevel)->GetSizeX() * 2 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() - inputData->levels->operator[](*inputData->currentLevel)->GetSizeX()]->titleType == bnc::PLAYER 
                    && 
                    r_Grid[r_Gates[i]->GetCellPosition() + inputData->levels->operator[](*inputData->currentLevel)->GetSizeX()]->titleType == bnc::NONE)
                    {
                        r_Gates[i]->MoveGateDown(inputData->levels->operator[](*inputData->currentLevel)->GetSizeX());
                        inputData->player->MovePlayerDown();
                        PlaySound(inputData->playerPushing);
                    }
                }

                m_Timer = 0;
            }

            // //* Particles
            if(inputData->particles->size() == 1 || inputData->particles->size() == 0)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    inputData->position->x += GetRandomValue(0, 60);
                    inputData->position->y += GetRandomValue(0, 10);

                    inputData->particles->push_back(std::shared_ptr<bnc::Particle>(new bnc::Particle{*inputData->position, *inputData->particleSize}));

                    *inputData->position = Vector2({r_Grid[inputData->player->GetPlayerPosition()]->position.x, r_Grid[inputData->player->GetPlayerPosition()]->position.y});
                }
            }
        }

        m_Timer++;

    }
}