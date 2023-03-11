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

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;

        void SetPosition(uint32_t position);
        void OnUpdate(std::vector<bnc::GridCell*>& cells);
    private:
        uint32_t m_Type = bnc::XOR;
        uint32_t m_GridCellPosition = 0;
        uint32_t m_GridCellNewPosition;
    };
}