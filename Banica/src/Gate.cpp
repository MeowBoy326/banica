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

    void Gate::OnUpdate(std::vector<std::shared_ptr<GridCell>>* cells)
    {
        cells->operator[](m_GridCellPosition)->titleType = bnc::NONE;
        m_GridCellPosition = m_GridCellNewPosition;
        cells->operator[](m_GridCellNewPosition)->titleType = bnc::GATE;
    }

    void Gate::MoveGateLeft()
    {
        m_GridCellNewPosition--;
    }

    void Gate::MoveGateRight()
    {
        m_GridCellNewPosition++;
    }

    void Gate::MoveGateUp(uint32_t sizeX)
    {
        m_GridCellNewPosition -= sizeX;
    }

    void Gate::MoveGateDown(uint32_t sizeX)
    {
        m_GridCellNewPosition += sizeX;
    }
}