#pragma once
#include "raylib.h"
#include "Data.h"
#include <memory>
#include <vector>

namespace bnc
{
    /// @brief It is responsible for rendering everything on the screen except the UI
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        /// @brief Renders everything
        /// @param data A pointer to the RenderData 
        void Render(std::shared_ptr<RenderData> data);

    private:
        std::shared_ptr<RenderData> m_Data;
        std::vector<std::shared_ptr<GridCell>> m_CellsInfo;

        float m_LineSize = 1.5;

        std::vector<Vector2> m_LigthPosition;
        uint32_t  m_Ligthcount = 0;

        /// @brief Clear the screen between frames
        void Clear();
        /// @brief Render the grid
        void RenderGrid();
        /// @brief Renders the player
        /// @param index Index in the grid where the player should be rendered
        inline void DrawPlayer(uint32_t index);
        /// @param index Index to the current cell in the GridCells vector
        inline void DrawTile(uint32_t index);
        /// @brief Render the gates
        /// @param index Index to the cells in the grid where the gate should be rendered
        void DrawGate(uint32_t index);
        /// @brief Render the lamps
        /// @param index Index to the cells in the grid where the lamp should be rendered
        void DrawLamp(uint32_t index);
        /// @brief Render the particle on the screen
        void RenderParticles();
        /// @brief Stores the position of the lamp on a vector that is later passed as a uniform to the lighting shader
        void GetLampsPosition();
    };
}