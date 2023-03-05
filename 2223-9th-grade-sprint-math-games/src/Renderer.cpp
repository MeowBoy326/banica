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

    void Renderer::Render(bnc::RenderData* data)
    {
        BeginDrawing();

        Clear();

        DrawRectangle(data->cubePositionX, (data->cubePositionY / 2) - 150, 300, 300, LIGHTGRAY);
        
        GuiSetStyle(DEFAULT, TEXT_SIZE, 40);
        GuiButton({ 10, 10, 300, 100 }, "TEST BUTTON");
        
        DrawFPS(0, 0);

        EndDrawing();
    }

    void Renderer::Clear()
    {
        ClearBackground(RAYWHITE);
    }
}