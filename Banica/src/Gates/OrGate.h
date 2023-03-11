#pragma
#include "Gate.h"


namespace bnc
{
    class OrGate: public Gate
    {
    public:
        OrGate(uint32_t position);
        ~OrGate();

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;
        void OnUpdate(std::vector<bnc::GridCell*>& cells);
    private:
        uint32_t m_Type = bnc::OR;
        uint32_t m_GridCellPosition = 0;
        uint32_t m_GridCellNewPosition;
    };
}