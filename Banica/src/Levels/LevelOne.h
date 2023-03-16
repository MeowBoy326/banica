#pragma once 
#include "Level.h"
#include "Player.h"
#include "Gates/Gates.h"
#include <vector>
#include <memory>

namespace bnc
{
    class LevelOne : public Level
    {
    public:
        LevelOne(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<Lamp>>* lamps);
        ~LevelOne();

        void SetGates();
        void SetLamps();
    };
}