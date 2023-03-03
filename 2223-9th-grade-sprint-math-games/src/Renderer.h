#pragma once
#include "raylib.h"
#include "RenderData.h"

namespace bn
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void Render(bn::RenderData* data);
    };
}