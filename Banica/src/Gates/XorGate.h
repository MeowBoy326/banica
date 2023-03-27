#pragma
#include "Gate.h"
#include "GridCell.h"
#include <vector>

namespace bnc
{
    class XorGate: public Gate
    {
    public:
        XorGate(uint32_t position);
        ~XorGate();
    };
}