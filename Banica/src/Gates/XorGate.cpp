#include "XorGate.h"

namespace bnc
{
    XorGate::XorGate(uint32_t position)
    {
        m_GridCellPosition = position;
    }

    XorGate::~XorGate()
    {

    }

    uint32_t XorGate::GetCellPosition() const
    {
        return m_GridCellPosition;
    }

    uint32_t XorGate::GetType() const
    {
        return m_Type;
    }
}