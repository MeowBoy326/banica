#pragma once
#include <stdint.h>
#include "GridCell.h"
#include <vector>
#include "Level.h"
#include <memory>
#include "Particle.h"
#include "Player.h"
#include <string>

/// @brief This is the namespace that contains everything for the game
namespace bnc
{

    enum
    {
        MAIN_MENU = 1,
        OPTIONS = 2,
        LEVEL_SELECT = 3,
        TUTORIAL = 4,
        GAME = 5
    };

    /// @brief This struct stores all the data that needs to be passed to the Renderer in the end of the frame
    struct RenderData
    {
        std::vector<std::shared_ptr<Level>>* levels;
        uint32_t* currentLevel;
        uint32_t* gameState;
        std::vector<std::shared_ptr<Particle>>* particles;
        Shader bloomShader;
        Shader lightShader;
        Texture2D spriteTexture;
    };


    /// @brief This struct stores all the data that needs to be passed to the UIRenderer in the end of the frame
    struct UIData
    {
        bool skipTutorial = false;
        bool isResetButtonPressed = false;
        bool isPlayButtonPressed = false;
        bool isQuitButtonPressed = false;
        bool isBackButtonPressed = false;
        bool levelSelected[10];
        std::vector<std::shared_ptr<Level>>* levels;
        std::string* p_Result = nullptr;
        Texture2D spriteTexture;
        Font mainFont;
        uint32_t* currentLevel;
        uint32_t* gameState;
        uint32_t* titleAnimCounter;
        Vector2 m_FirstGatePosition;
        Texture2D mainMenuBg;
    };

    /// @brief This struct stores all the data that needs to be passed to the InputHandler
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

    /// @brief This struct stores all the data that needs to be passed to the LevelGenerator
    struct LevelGenerationData
    {
        std::vector<std::shared_ptr<bnc::Level>>* levels;
        std::vector<std::shared_ptr<GridCell>>* gridCells;
        uint32_t* currentLevel = nullptr;
        std::shared_ptr<Player> player;
        std::vector<std::shared_ptr<bnc::Gate>>* gates;
        std::vector<std::shared_ptr<bnc::Lamp>>* lamps;
        std::vector<std::shared_ptr<LevelSolution>>* solutions;
        std::string* p_Result = nullptr;
    };
}
