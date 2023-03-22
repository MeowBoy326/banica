#pragma once
#include "raylib.h"
#include "Data.h"
#include <memory>
#include <vector>

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

        float m_LineSize = 1.5;

        std::vector<Vector2> m_LigthPosition;
        uint32_t  m_Ligthcount = 0;

        void Clear();
        void RenderGrid();
        void RenderPlayer();
        void RenderGates();
        void RenderLamps();
        void RenderParticles();
        void GetLampsPosition();
    };
}