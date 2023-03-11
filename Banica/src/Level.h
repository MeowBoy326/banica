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

        virtual std::vector<bnc::GridCell*>& GetGridCells() const = 0;
        virtual std::vector<bnc::Gate*>& GetGates() = 0;
        virtual uint32_t GetSizeX() const = 0;
        virtual uint32_t GetSizeY() const = 0;
        virtual void SetGates() = 0; 

    private:
        std::vector<bnc::GridCell*>* m_GridCells;
        std::vector<bnc::Gate*> m_Gates;
        uint32_t m_SizeX = 0;
        uint32_t m_SizeY = 0;
    };
}