#include "NotGate.h"

namespace bnc
{
    NotGate::NotGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;

        m_Type = bnc::NOT;
    }

    NotGate::~NotGate()
    {

    }
}