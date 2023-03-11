#pragma
#include "Gate.h"


namespace bnc
{
    class XorGate: public Gate
    {
    public:
        XorGate(uint32_t position);
        ~XorGate();

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;
    private:
        uint32_t m_Type = bnc::XOR;
        uint32_t m_GridCellPosition = 0;
    };
}