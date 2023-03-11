#include "AndGate.h"

namespace bnc
{
    AndGate::AndGate(uint32_t position)
    {
        m_GridCellPosition = position;
    }

    AndGate::~AndGate()
    {

    }

    uint32_t AndGate::GetCellPosition() const
    {
        return m_GridCellPosition;
    }

    uint32_t AndGate::GetType() const
    {
        return m_Type;
    }
}