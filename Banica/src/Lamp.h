#pragma once
#include <memory>
#include "raylib.h"
#include <stdint.h>
#include <vector>
#include "GridCell.h"

namespace bnc
{
    class Lamp
    {
    public:
        Lamp(uint32_t position, uint32_t type);
        ~Lamp();

        uint32_t GetPosition() const;
        uint32_t GetType() const;

        void OnUpdate(std::vector<std::shared_ptr<GridCell>>& grid);
        void SetState(uint32_t val);
    private:
        uint32_t m_Type;
        uint32_t m_Position;
    };
}