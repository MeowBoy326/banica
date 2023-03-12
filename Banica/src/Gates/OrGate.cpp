#include "OrGate.h"

namespace bnc
{
    OrGate::OrGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;

        m_Type = bnc::OR;
    }

    OrGate::~OrGate()
    {

    }
}