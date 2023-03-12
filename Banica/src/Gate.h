#pragma once
#include <stdint.h>
#include <vector>
#include "GridCell.h"

namespace bnc
{
    enum
    {
        AND,
        OR,
        XOR,
        NOT
    };

    class Gate
    {
    public:
        Gate();
        ~Gate();

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;
        void OnUpdate(std::vector<bnc::GridCell*>* cells);

        void MoveGateLeft();
        void MoveGateRight();
        void MoveGateUp(uint32_t sizeX);
        void MoveGateDown(uint32_t sizeX);
    protected:
        std::vector<bnc::GridCell*>* m_GridCells;

        uint32_t m_Type;
        uint32_t m_GridCellPosition;
        uint32_t m_GridCellNewPosition;
    };
}
