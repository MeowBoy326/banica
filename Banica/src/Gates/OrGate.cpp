#include "OrGate.h"

namespace bnc
{
    OrGate::OrGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;
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

    void OrGate::OnUpdate(std::vector<bnc::GridCell*>& cells)
    {
        cells[m_GridCellPosition]->titleType = bnc::NONE;
        m_GridCellPosition = m_GridCellNewPosition;
        cells[m_GridCellNewPosition]->titleType = bnc::GATE;
    }
}