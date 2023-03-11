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
    private:
        uint32_t m_Type = bnc::OR;
        uint32_t m_GridCellPosition = 0;
    };
}