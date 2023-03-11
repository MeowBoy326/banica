#pragma once 
#include "Level.h"
#include "Player.h"
#include "Gates/Gates.h"
#include <vector>

namespace bnc
{
    class LevelOne : public Level
    {
    public:
        LevelOne(std::vector<bnc::GridCell*>* grid, bnc::Player& player, std::vector<Gate*>* gates);
        ~LevelOne();

        std::vector<bnc::GridCell*>& GetGridCells() const;
        std::vector<bnc::Gate*>& GetGates();
        uint32_t GetSizeX() const;
        uint32_t GetSizeY() const;

        void SetGates();
    private:
        std::vector<bnc::GridCell*>* m_GridCells;
        std::vector<bnc::Gate*>* m_Gates;
        uint32_t m_SizeX = 10;
        uint32_t m_SizeY = 10;
    };
}