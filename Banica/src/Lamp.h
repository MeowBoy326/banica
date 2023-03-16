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
        Lamp(uint32_t position, bool state);
        ~Lamp();

        uint32_t GetPosition() const;
        bool GetIsOn() const;

        void OnUpdate(std::vector<std::shared_ptr<GridCell>>& grid);
        void SetIsOn(bool state);
    private:
        bool m_IsOn = false;
        uint32_t m_Position;
    };
}