#pragma once
#include <vector>
#include <memory>
#include <stdint.h>
#include "GridCell.h"
#include "Gate.h"

namespace bnc
{
    // THIS CLASS IS MEANT TO BE INHERITED IT IS ONLY A TEMPLATE
    class Level
    {
    public:
        Level();
        ~Level();

        std::vector<std::shared_ptr<bnc::GridCell>>& GetGridCells() const;
        std::vector<std::shared_ptr<bnc::Gate>>& GetGates() const;
        uint32_t GetSizeX() const;
        uint32_t GetSizeY() const;

        virtual void SetGates() = 0; 

    protected:
        std::vector<std::shared_ptr<bnc::GridCell>>* m_GridCells;
        std::vector<std::shared_ptr<bnc::Gate>>* m_Gates;
        uint32_t m_SizeX;
        uint32_t m_SizeY;
    };
}