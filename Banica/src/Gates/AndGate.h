#pragma
#include "Gate.h"


namespace bnc
{
    class AndGate: public Gate
    {
    public:
        AndGate(uint32_t position);
        ~AndGate();

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;
    private:
        uint32_t m_Type = bnc::AND;
        uint32_t m_GridCellPosition = 0;
    };
}