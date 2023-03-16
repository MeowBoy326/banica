#include "Lamp.h"

namespace bnc
{
    Lamp::Lamp(uint32_t position, uint32_t type)
    {
        m_Position = position;
        m_Type = type;
    }

    Lamp::~Lamp()
    {

    }

    uint32_t Lamp::GetType() const
    {
        return m_Type;
    }

    uint32_t Lamp::GetPosition() const
    {
        return m_Position;
    }

    void Lamp::SetState(uint32_t val)
    {
        m_Type = val;
    }


    void Lamp::OnUpdate(std::vector<std::shared_ptr<GridCell>>& grid)
    {
        grid[m_Position]->titleType = bnc::LAMP;
    }
}