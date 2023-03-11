#include "NotGate.h"

namespace bnc
{
    NotGate::NotGate(uint32_t position)
    {
        m_GridCellPosition = position;
        m_GridCellNewPosition = position;
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
    void NotGate::OnUpdate(std::vector<bnc::GridCell*>& cells)
    {
        cells[m_GridCellPosition]->titleType = bnc::NONE;
        m_GridCellPosition = m_GridCellNewPosition;
        cells[m_GridCellNewPosition]->titleType = bnc::GATE;
    }
}