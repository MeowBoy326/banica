#include "Renderer.h"

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"
#include <iostream>

namespace bnc
{
    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::RenderGrid()
    {
        m_CellsInfo = m_Data->levels->operator[](*m_Data->currentLevel)->GetGridCells();

        DrawRectangleLinesEx(Rectangle({float(m_CellsInfo[0]->position.x - 1.5f), float(m_CellsInfo[0]->position.y - 1.5f), float(m_Data->levels->operator[](*m_Data->currentLevel)->GetSizeX() * 60 + 3.0f), float(m_Data->levels->operator[](*m_Data->currentLevel)->GetSizeY() * 60 + 3.0f)}), 1.5f, LIGHTGRAY);

        for(size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            DrawRectangleLinesEx(Rectangle({m_CellsInfo[i]->position.x, m_CellsInfo[i]->position.y, 60, 60}), 1.5f, LIGHTGRAY);
        }
    }

    void Renderer::RenderPlayer()
    {
        for(size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            if(m_CellsInfo[i]->titleType == bnc::PLAYER)
            {
                DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, DARKGREEN);
            }
        }
    }

    void Renderer::RenderGates()
    {
        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            if(m_CellsInfo[i]->titleType == bnc::GATE)
            {
                //* Find the type of the gate and render it accordingly
                uint32_t temp; 
                for (size_t j = 0; j < m_Data->levels->operator[](*m_Data->currentLevel)->GetGates().size(); j++)
                {
                    if(m_Data->levels->operator[](*m_Data->currentLevel)->GetGates()[j]->GetCellPosition() == i)
                    {
                       temp = m_Data->levels->operator[](*m_Data->currentLevel)->GetGates()[j]->GetType(); 
                    }
                }
                
                switch (temp)
                {
                case bnc::AND:
                    DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, DARKBLUE);
                    break;
                case bnc::OR:
                    DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, RED);
                    break;
                case bnc::NOT:
                    DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, PURPLE);
                    break;
                case bnc::XOR:
                    DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, YELLOW);
                    break; 
                default:
                    break;
                }
            }
        }
    }

    void Renderer::RenderLamps()
    {
        std::vector<std::shared_ptr<Lamp>>& r_lamps = m_Data->levels->operator[](*m_Data->currentLevel)->GetLamps();


        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            uint32_t temp; 

            for (size_t j = 0; j < r_lamps.size(); j++)
            {
                if(r_lamps[j]->GetPosition() == i)
                {
                    temp = r_lamps[j]->GetType(); 
                }
            }

            if(m_CellsInfo[i]->titleType == bnc::LAMP)
            {
                if(temp == bnc::LAMP_ON)
                {
                    DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, GOLD);
                }
                else
                {
                    DrawRectangle(m_CellsInfo[i]->position.x + 1.5f, m_CellsInfo[i]->position.y + 1.5f, 60 - 3.0f, 60 - 3.0f, DARKGRAY);
                }
            }
        }

    }

    void Renderer::Render(std::shared_ptr<bnc::RenderData> data)
    {
        m_Data = data;

        BeginDrawing();

        Clear();

        RenderGrid();
        RenderPlayer();
        RenderGates();
        RenderLamps();

        DrawFPS(0, 0);

        EndDrawing();
    }

    void Renderer::Clear()
    {
        ClearBackground(RAYWHITE);
    }
}