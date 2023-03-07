#pragma once
#include <vector>
#include <stdint.h>
#include "GridCell.h"

namespace bnc
{
    // THIS CLASS IS MEANT TO BE INHERITED IT IS ONLY A TEMPLATE
    class Level
    {
    public:
        Level();
        virtual ~Level();

        virtual std::vector<GridCell*>* GetGridCells() const = 0;
        virtual  uint32_t GetSizeX() const = 0;
        virtual  uint32_t GetSizeY() const = 0;

    private:
        std::vector<GridCell*>* m_GridCells;
        uint32_t m_SizeX = 0;
        uint32_t m_SizeY = 0;
    };
}