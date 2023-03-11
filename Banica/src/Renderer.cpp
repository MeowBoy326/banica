#include "Renderer.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace bnc
{
    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {
        delete m_Data;
    }

    void Renderer::RenderGrid()
    {
        m_CellsInfo = m_Data->levels->operator[](*m_Data->currentLevel)->GetGridCells();

        DrawRectangleLinesEx(Rectangle({float(m_CellsInfo[0]->positionX - 1.5f), float(m_CellsInfo[0]->positionY - 1.5f), float(m_Data->levels->operator[](*m_Data->currentLevel)->GetSizeX() * 60 + 3.0f), float(m_Data->levels->operator[](*m_Data->currentLevel)->GetSizeY() * 60 + 3.0f)}), 1.5f, LIGHTGRAY);

        for(size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            DrawRectangleLinesEx(Rectangle({m_CellsInfo[i]->positionX, m_CellsInfo[i]->positionY, 60, 60}), 1.5f, LIGHTGRAY);
        }
    }

    void Renderer::RenderPlayer()
    {
        for(size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            if(m_CellsInfo[i]->isPlayerHere)
            {
                DrawRectangle(m_CellsInfo[i]->positionX + 1.5f, m_CellsInfo[i]->positionY + 1.5f, 60 - 3.0f, 60 - 3.0f, DARKGREEN);
            }
        }
    }

    void Renderer::RenderGates()
    {
        uint32_t currentGate = 0;

        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            if(m_CellsInfo[i]->isGateHere == true)
            {
                //* Find the type of the gate and render it accordingly
                switch (m_Data->levels->operator[](*m_Data->currentLevel)->GetGates()[currentGate]->GetType())
                {
                case bnc::AND:
                    DrawRectangle(m_CellsInfo[i]->positionX + 1.5f, m_CellsInfo[i]->positionY + 1.5f, 60 - 3.0f, 60 - 3.0f, DARKBLUE);
                    break;
                case bnc::OR:
                    DrawRectangle(m_CellsInfo[i]->positionX + 1.5f, m_CellsInfo[i]->positionY + 1.5f, 60 - 3.0f, 60 - 3.0f, RED);
                    break;
                case bnc::NOT:
                    DrawRectangle(m_CellsInfo[i]->positionX + 1.5f, m_CellsInfo[i]->positionY + 1.5f, 60 - 3.0f, 60 - 3.0f, PURPLE);
                    break;
                case bnc::XOR:
                    DrawRectangle(m_CellsInfo[i]->positionX + 1.5f, m_CellsInfo[i]->positionY + 1.5f, 60 - 3.0f, 60 - 3.0f, YELLOW);
                    break; 
                default:
                    break;
                }

                currentGate++;
            }
        }
    }

    void Renderer::Render(bnc::RenderData* data)
    {
        m_Data = data;

        BeginDrawing();

        Clear();

        RenderGrid();
        RenderPlayer();
        RenderGates();

        DrawFPS(0, 0);

        EndDrawing();
    }

    void Renderer::Clear()
    {
        ClearBackground(RAYWHITE);
    }
}