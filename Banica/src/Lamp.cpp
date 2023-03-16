#include "Lamp.h"

namespace bnc
{
    Lamp::Lamp(uint32_t position, bool state)
    {
        m_Position = position;
        m_IsOn = state;
    }

    Lamp::~Lamp()
    {

    }

    bool Lamp::GetIsOn() const
    {
        return m_IsOn;
    }

    uint32_t Lamp::GetPosition() const
    {
        return m_Position;
    }

    void Lamp::SetIsOn(bool state)
    {
        m_IsOn = state;
    }


    void Lamp::OnUpdate(std::vector<std::shared_ptr<GridCell>>& grid)
    {
        grid[m_Position]->titleType = bnc::LAMP;
    }
}