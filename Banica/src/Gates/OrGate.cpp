#include "OrGate.h"

namespace bnc
{
    OrGate::OrGate(uint32_t position)
    {
        m_GridCellPosition = position;
    }

    OrGate::~OrGate()
    {

    }

    uint32_t OrGate::GetCellPosition() const
    {
        return m_GridCellPosition;
    }

    uint32_t OrGate::GetType() const
    {
        return m_Type;
    }
}