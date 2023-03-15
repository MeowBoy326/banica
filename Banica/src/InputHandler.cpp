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

    void InputHandler::HandleInput(std::shared_ptr<bnc::Player> player, std::vector<std::shared_ptr<Level>>& levels, uint32_t& curretnLevel)
    {
        std::vector<std::shared_ptr<bnc::GridCell> >& r_Grid = levels[curretnLevel]->GetGridCells();
        std::vector<std::shared_ptr<bnc::Gate> >& r_Gates = levels[curretnLevel]->GetGates();

        //* RIGHT
        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player->GetPlayerPosition() < r_Grid.size() - 1)
        {
            if(m_Timer >= 12)
            {
                if(r_Grid[player->GetPlayerPosition() + 1]->isMovable == true)
                    player->MovePlayerRight();

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
                if(r_Grid[player->GetPlayerPosition() - 1]->isMovable == true)
                    player->MovePlayerLeft();

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
                if(r_Grid[player->GetPlayerPosition() - levels[curretnLevel]->GetSizeX()]->isMovable == true)
                    player->MovePlayerUp();

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

                if(r_Grid[player->GetPlayerPosition() + levels[curretnLevel]->GetSizeX()]->isMovable == true)
                    player->MovePlayerDown();

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
                    }
                }

                m_Timer = 0;
            }
        }

        m_Timer++;
    }
}