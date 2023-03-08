#pragma once 
#include "Level.h"

namespace bnc
{
    class LevelOne : public Level
    {
    public:
        LevelOne(std::vector<GridCell*>* grid);
        virtual ~LevelOne();

        std::vector<GridCell*>& GetGridCells() const;
        uint32_t GetSizeX() const ;
        uint32_t GetSizeY() const ;
    private:
        std::vector<GridCell*>* m_GridCells;
        uint32_t m_SizeX = 10;
        uint32_t m_SizeY = 10;
    };
}