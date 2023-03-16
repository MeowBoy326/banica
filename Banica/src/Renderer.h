#pragma once
#include "raylib.h"
#include "RenderData.h"
#include <memory>

namespace bnc
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void Render(std::shared_ptr<RenderData> data);

    private:
        std::shared_ptr<RenderData> m_Data;
        std::vector<std::shared_ptr<GridCell>> m_CellsInfo;

        void Clear();
        void RenderGrid();
        void RenderPlayer();
        void RenderGates();
        void RenderLamps();
    };
}