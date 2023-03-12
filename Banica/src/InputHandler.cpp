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

    void InputHandler::HandleInput(bnc::Player* player, std::vector<bnc::Level*>& levels, uint32_t& curretnLevel)
    {
        //* RIGHT
        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player->GetPlayerPosition() < levels[curretnLevel]->GetGridCells().size() - 1)
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerRight();

                for (size_t i = 0; i < levels[curretnLevel]->GetGates().size(); i++)
                {
                    if(levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() - 1]->titleType == bnc::PLAYER 
                    && 
                    levels[curretnLevel]->GetGates()[i]->GetCellPosition() < levels[curretnLevel]->GetGridCells().size()  - levels[curretnLevel]->GetSizeX() - 1 
                    && 
                    levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() + 1]->titleType == bnc::NONE)
                    {
                        levels[curretnLevel]->GetGates()[i]->MoveGateRight();
                    }
                }

                m_Timer = 0;
            }
        }

        //* LEFT
        if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && player->GetPlayerPosition() > 0)
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerLeft();

                for (size_t i = 0; i < levels[curretnLevel]->GetGates().size(); i++)
                {
                    if(levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() + 1]->titleType == bnc::PLAYER 
                    &&
                    levels[curretnLevel]->GetGates()[i]->GetCellPosition() > levels[curretnLevel]->GetSizeX() 
                    &&
                    levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() - 1]->titleType == bnc::NONE)
                    {
                        levels[curretnLevel]->GetGates()[i]->MoveGateLeft();
                    }
                }

                m_Timer = 0;
            }
        }

        //* UP
        if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && player->GetPlayerPosition() > levels[curretnLevel]->GetSizeX())
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerUp();

                for (size_t i = 0; i < levels[curretnLevel]->GetGates().size(); i++)
                {
                    if(levels[curretnLevel]->GetGates()[i]->GetCellPosition() > levels[curretnLevel]->GetSizeX() * 2 
                    && 
                    levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() + levels[curretnLevel]->GetSizeX()]->titleType == bnc::PLAYER 
                    && 
                    levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() - levels[curretnLevel]->GetSizeX()]->titleType == bnc::NONE)
                    {
                        levels[curretnLevel]->GetGates()[i]->MoveGateUp(levels[curretnLevel]->GetSizeX());
                    }
                }

                m_Timer = 0;
            }
        }

        //* DOWN
        if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && player->GetPlayerPosition() < levels[curretnLevel]->GetGridCells().size() - levels[curretnLevel]->GetSizeX())
        {
            if(m_Timer >= 12)
            {

                player->MovePlayerDown();

                for (size_t i = 0; i < levels[curretnLevel]->GetGates().size(); i++)
                {
                    if(levels[curretnLevel]->GetGates()[i]->GetCellPosition() < levels[curretnLevel]->GetGridCells().size() - levels[curretnLevel]->GetSizeX() * 2 
                    && 
                    levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() - levels[curretnLevel]->GetSizeX()]->titleType == bnc::PLAYER 
                    && 
                    levels[curretnLevel]->GetGridCells()[levels[curretnLevel]->GetGates()[i]->GetCellPosition() + levels[curretnLevel]->GetSizeX()]->titleType == bnc::NONE)
                    {
                        levels[curretnLevel]->GetGates()[i]->MoveGateDown(levels[curretnLevel]->GetSizeX());
                    }
                }

                m_Timer = 0;
            }
        }

        m_Timer++;
    }
}