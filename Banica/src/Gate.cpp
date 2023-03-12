#include "Gate.h"

namespace bnc
{
    Gate::Gate()
    {

    }

    Gate::~Gate()
    {

    }

    uint32_t Gate::GetCellPosition() const
    {
        return m_GridCellPosition;
    }

    uint32_t Gate::GetType() const
    {
        return m_Type;
    }

    void Gate::OnUpdate(std::vector<bnc::GridCell*>* cells)
    {
        cells->operator[](m_GridCellPosition)->titleType = bnc::NONE;
        m_GridCellPosition = m_GridCellNewPosition;
        cells->operator[](m_GridCellNewPosition)->titleType = bnc::GATE;
    }

    void Gate::MoveGateLeft()
    {

    }

    void Gate::MoveGateRight()
    {
    
    }

    void Gate::MoveGateUp()
    {

    }

    void Gate::MoveGateDown()
    {

    }
}