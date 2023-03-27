#pragma
#include "Gate.h"


namespace bnc
{
    class OrGate: public Gate
    {
    public:
        OrGate(uint32_t position);
        ~OrGate();
    };
}