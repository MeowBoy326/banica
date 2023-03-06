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
        for(size_t i = 0; i < m_Data->gridCells->size(); i++)
        {
            DrawRectangle(m_Data->gridCells->operator[](i)->positionX, m_Data->gridCells->operator[](i)->positionY, 60, 60, LIGHTGRAY);
            DrawRectangle(m_Data->gridCells->operator[](i)->positionX + 2, m_Data->gridCells->operator[](i)->positionY + 2, 56, 56, RAYWHITE);

            // DrawRectangleV(Vector2({m_Data->gridCells->operator[](i)->positionX, m_Data->gridCells->operator[](i)->positionY}), Vector2({60, 60}), LIGHTGRAY);
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