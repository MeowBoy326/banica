#pragma
#include "Gate.h"
#include "GridCell.h"
#include <vector>


namespace bnc
{
    class AndGate: public Gate
    {
    public:
        AndGate(uint32_t position);
        ~AndGate();
    };
}