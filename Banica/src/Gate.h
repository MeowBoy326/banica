#pragma once
#include <stdint.h>
#include <vector>
#include "GridCell.h"
#include <memory>

namespace bnc
{
    enum
    {
        AND = 1,
        OR = 2,
        XOR = 3,
        NOT = 4
    };

    class Gate
    {
    public:
        Gate();
        ~Gate();

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;
        void OnUpdate(std::vector<std::shared_ptr<bnc::GridCell>>* cells);
        
        void MoveGateLeft();
        void MoveGateRight();
        void MoveGateUp(uint32_t sizeX);
        void MoveGateDown(uint32_t sizeX);
    protected:
        std::vector<std::shared_ptr<bnc::GridCell>>* m_GridCells;

        uint32_t m_Type;
        uint32_t m_GridCellPosition;
        uint32_t m_GridCellNewPosition;

    };
}
