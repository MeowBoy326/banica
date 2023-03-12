#include "XorGate.h"

namespace bnc
{
    XorGate::XorGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;
        
        m_Type = bnc::XOR;
    }

    XorGate::~XorGate()
    {

    }
}