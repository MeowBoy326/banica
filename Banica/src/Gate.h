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

        virtual uint32_t GetType() const = 0;
        virtual uint32_t GetCellPosition() const = 0;
        virtual void OnUpdate(std::vector<bnc::GridCell*>& cells) = 0;
    private:
        uint32_t m_Type;
        uint32_t m_GridCellPosition;
        uint32_t m_GridCellNewPosition;
    };
}
