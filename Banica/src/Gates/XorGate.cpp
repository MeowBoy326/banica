#include "XorGate.h"

namespace bnc
{
    XorGate::XorGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;
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

    void XorGate::OnUpdate(std::vector<bnc::GridCell*>& cells)
    {
        cells[m_GridCellPosition]->titleType = bnc::NONE;
        m_GridCellPosition = m_GridCellNewPosition;
        cells[m_GridCellNewPosition]->titleType = bnc::GATE;
    }
}