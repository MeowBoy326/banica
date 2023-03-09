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

    void InputHandler::HandleInput(Player* player, std::vector<Level*>& levels, uint32_t& curretnLevel)
    {

        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player->GetPlayerPosition() < levels[curretnLevel]->GetGridCells().size() - 1)
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerRight();
                m_Timer = 0;
            }
        }


        if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && player->GetPlayerPosition() > 0)
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerLeft();
                m_Timer = 0;
            }
        }

        if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && player->GetPlayerPosition() > levels[curretnLevel]->GetSizeX())
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerUp();
                m_Timer = 0;
            }
        }

        if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && player->GetPlayerPosition() < levels[curretnLevel]->GetGridCells().size() - levels[curretnLevel]->GetSizeX())
        {
            if(m_Timer >= 12)
            {
                player->MovePlayerDown();
                m_Timer = 0;
            }
        }

        m_Timer++;
    }
}