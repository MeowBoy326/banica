#pragma once 
#include "Level.h"
#include "Player.h"
#include "Gates/Gates.h"
#include <vector>
#include <memory>

namespace bnc
{
    class LevelTwo : public Level
    {
    public:
        LevelTwo(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<Lamp>>* lamps); 
        ~LevelTwo();

        void SetGates();
        void SetLamps();

    };
}