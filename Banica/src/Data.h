#pragma once
#include <stdint.h>
#include "GridCell.h"
#include <vector>
#include "Level.h"
#include <memory>
#include "Particle.h"
#include "Player.h"

namespace bnc
{
    struct RenderData
    {
        std::vector<std::shared_ptr<Level>>* levels;
        uint32_t* currentLevel;
        std::vector<std::shared_ptr<Particle>>* particles;
        Shader bloomShader;
        Shader lightShader;
        Texture2D spriteTexture;
    };

    struct UIData
    {
        bool isResetButtonPressed = false;
    };

    struct InputHandlerData
    {
        std::shared_ptr<bnc::Player> player; 
        std::vector<std::shared_ptr<Level>>* levels; 
        uint32_t* currentLevel;
        std::vector<std::shared_ptr<bnc::Particle>>* particles; 
        Vector2* position;
        uint32_t* particleSize;
        Sound playerMovement;
        Sound playerPushing;
    };

    struct LevelGenerationData
    {
        std::vector<std::shared_ptr<bnc::Level>>* levels;
        std::vector<std::shared_ptr<GridCell>>* gridCells;
        uint32_t* currentLevel;
        std::shared_ptr<Player> player;
        std::vector<std::shared_ptr<bnc::Gate>>* gates;
        std::vector<std::shared_ptr<bnc::Lamp>>* lamps;
        std::vector<std::shared_ptr<LevelSolution>>* solutions;
    };
}
