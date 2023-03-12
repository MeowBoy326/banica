#pragma once 
#include "Level.h"
#include "Player.h"
#include "Gates/Gates.h"
#include <vector>

namespace bnc
{
    class LevelOne : public Level
    {
    public:
        LevelOne(std::vector<bnc::GridCell*>* grid, bnc::Player& player, std::vector<Gate*>* gates);
        ~LevelOne();
        void SetGates();
    };
}