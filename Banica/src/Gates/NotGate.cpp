#include "NotGate.h"

namespace bnc
{
    NotGate::NotGate(uint32_t position)
    {
        m_GridCellPosition = position;
    }

    NotGate::~NotGate()
    {

    }

    uint32_t NotGate::GetCellPosition() const
    {
        return m_GridCellPosition;
    }

    uint32_t NotGate::GetType() const
    {
        return m_Type;
    }
}