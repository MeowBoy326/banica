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
        DrawRectangle(data->cubePositionX, (data->cubePositionY / 2) - 150, 300, 300, LIGHTGRAY);
        
        GuiSetStyle(DEFAULT, TEXT_SIZE, 40);
        GuiButton({ 10, 10, 300, 100 }, "TEST BUTTON");
    }
}