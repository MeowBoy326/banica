#include "AndGate.h"

namespace bnc
{
    AndGate::AndGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;
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

    void AndGate::OnUpdate(std::vector<bnc::GridCell*>& cells)
    {
        cells[m_GridCellPosition]->titleType = bnc::NONE;
        m_GridCellPosition = m_GridCellNewPosition;
        cells[m_GridCellNewPosition]->titleType = bnc::GATE;
    }
}