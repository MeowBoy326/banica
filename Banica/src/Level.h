#pragma once
#include <vector>
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

        std::vector<bnc::GridCell*>& GetGridCells() const;
        std::vector<bnc::Gate*>& GetGates() const;
        uint32_t GetSizeX() const;
        uint32_t GetSizeY() const;

        virtual void SetGates() = 0; 

    protected:
        std::vector<bnc::GridCell*>* m_GridCells;
        std::vector<bnc::Gate*>* m_Gates;
        uint32_t m_SizeX;
        uint32_t m_SizeY;
    };
}