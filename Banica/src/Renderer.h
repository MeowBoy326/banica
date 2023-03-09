#pragma once
#include "raylib.h"
#include "RenderData.h"

namespace bnc
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void Render(bnc::RenderData* data);

    private:
        RenderData* m_Data;
        std::vector<GridCell*> m_CellsInfo;

        void Clear();
        void RenderGrid();
        void RenderPlayer();
    };
}