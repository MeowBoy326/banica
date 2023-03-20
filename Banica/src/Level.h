#pragma once
#include <vector>
#include <memory>
#include <stdint.h>
#include "GridCell.h"
#include "Gate.h"
#include "Lamp.h"
#include <vector>
#include "Solution.h"

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
        std::vector<std::shared_ptr<bnc::Lamp>>& GetLamps() const;
        uint32_t GetSizeX() const;
        uint32_t GetSizeY() const;

        virtual void SetGates() = 0; 
        virtual void SetLamps() = 0; 
    protected:
        std::vector<std::shared_ptr<bnc::GridCell>>* m_GridCells;
        std::vector<std::shared_ptr<bnc::Gate>>* m_Gates;
        std::vector<std::shared_ptr<bnc::Lamp>>* m_Lamps;
        std::vector<std::shared_ptr<bnc::LevelSolution>>* m_Solution;

        uint32_t m_SizeX;
        uint32_t m_SizeY;
    };
}