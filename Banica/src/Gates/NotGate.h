#pragma
#include "Gate.h"


namespace bnc
{
    class NotGate: public Gate
    {
    public:
        NotGate(uint32_t position);
        ~NotGate();
    };
}