#pragma once
#include <vector>
#include "Solution.h"
#include "raylib.h"
#include <stdint.h>
#include "Renderer.h"
#include "GridCell.h"
#include "LevelGeneration.h"
#include "Player.h"
#include "InputHandler.h"
#include "Gate.h"
#include <memory>
#include "Lamp.h"
#include "Particle.h"
#include "ParticleHandler.h"
#include "UIRenderer.h"
#include "Data.h"

namespace bnc
{
    /// @brief This is the main class from witch the flow of the game is controlled 
    class Game
    {
    public:
        /// @brief The constructor initiales the window and calls the member methods Configs() and VariableInitialization()
        /// @param width This is the width of the window
        /// @param height This is the height of the window 
        /// @param title This is the title of the window
        /// @see Configs() 
        /// @see VariableInitialization()
        Game(uint32_t width, uint32_t height, const char* title);
        ~Game();

       /// @brief This method runs the game
        void Run();

    private:
        std::unique_ptr<bnc::Renderer> m_Renderer;
        std::shared_ptr<bnc::RenderData> m_Data;
        std::shared_ptr<bnc::UIData> m_UIData;
        std::shared_ptr<bnc::Player> m_Player;
        std::unique_ptr<bnc::ParticleHandler> m_ParticleHandler;

        std::vector<std::shared_ptr<bnc::GridCell>> m_GridCells;
        std::unique_ptr<LevelGenerator> m_LevelGenerator;

        std::vector<std::shared_ptr<Level>> m_Levels;
        std::vector<std::shared_ptr<Lamp>> m_Lamps;

        std::unique_ptr<bnc::InputHandler> m_InputHandler;

        std::vector<std::shared_ptr<Gate>> m_Gates;

        std::vector<std::shared_ptr<bnc::LevelSolution>> m_Solutions;
        std::vector<std::shared_ptr<bnc::Particle>> m_Particles;
        std::unique_ptr<bnc::UIRenderer> m_UIRenderer;

        Sound m_PlayerMovement;
        Sound m_PlayerPushing;
        Sound m_ButtonClick;
        Sound m_CompleteLevel;

        Shader m_BloomShader;
        Shader m_LightShader;

        Texture2D m_SpriteTexture;

        Font m_MainFont;

        uint32_t m_CurrentLevel = 0;

        Vector2 m_ParticleNewPosition;
        uint32_t m_ParticleSize;
        
        std::string m_Result;
        
        /// @brief This method runs every frame and updates all the required variables
        void Update();
        /// @brief This method sets all configurations for raylib
        void Configs();
        /// @brief This method run once at the begining of the game
        void VariableInitialization();
        /// @brief This method clear the level
        void ClearLevel();
    };
}
