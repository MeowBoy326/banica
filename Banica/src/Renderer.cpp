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

    }

    void Renderer::RenderGrid()
    {
        std::vector<GridCell*> cellsInfo = m_Data->levels->operator[](*m_Data->currentLevel)->GetGridCells();

        DrawRectangleLinesEx(Rectangle({float(cellsInfo[0]->positionX - 1.5f), float(cellsInfo[0]->positionY - 1.5f), float(m_Data->levels->operator[](*m_Data->currentLevel)->GetSizeX() * 60 + 3.0f), float(m_Data->levels->operator[](*m_Data->currentLevel)->GetSizeY() * 60 + 3.0f)}), 1.5f, LIGHTGRAY);

        for(size_t i = 0; i < cellsInfo.size(); i++)
        {
            DrawRectangleLinesEx(Rectangle({cellsInfo[i]->positionX, cellsInfo[i]->positionY, 60, 60}), 1.5f, LIGHTGRAY);
        }
    }

    void Renderer::Render(bnc::RenderData* data)
    {
        m_Data = data;

        BeginDrawing();

        Clear();

        RenderGrid();

        DrawFPS(0, 0);

        EndDrawing();
    }

    void Renderer::Clear()
    {
        ClearBackground(RAYWHITE);
    }
}