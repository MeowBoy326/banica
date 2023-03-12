#include "AndGate.h"

namespace bnc
{
    AndGate::AndGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;

        m_Type = bnc::AND;
    }

    AndGate::~AndGate()
    {

    }
}