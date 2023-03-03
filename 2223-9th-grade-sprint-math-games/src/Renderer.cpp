#include "Renderer.h"

namespace bn
{
    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::Render(bn::RenderData* data)
    {
        DrawRectangle(data->cubePositionX, (data->cubePositionY / 2) - 150, 300, 300, LIGHTGRAY);
    }
}