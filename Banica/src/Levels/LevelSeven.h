#pragma once 
#include "Level.h"
#include "Player.h"
#include "Gates/Gates.h"
#include <vector>
#include <memory>
#include "Solution.h"

namespace bnc
{
    class LevelSeven : public Level
    {
    public:
        LevelSeven(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<Lamp>>* lamps, std::vector<std::shared_ptr<LevelSolution>>& solutions); 
        ~LevelSeven();

        void SetGates();
        void SetLamps(std::string& r_Result);
    };
}