#pragma
#include "Gate.h"


namespace bnc
{
    class NotGate: public Gate
    {
    public:
        NotGate(uint32_t position);
        ~NotGate();

        uint32_t GetType() const;
        uint32_t GetCellPosition() const;
        void OnUpdate(std::vector<bnc::GridCell*>& cells);
    private:
        uint32_t m_Type = bnc::NOT;
        uint32_t m_GridCellPosition = 0;
        uint32_t m_GridCellNewPosition;
    };
}