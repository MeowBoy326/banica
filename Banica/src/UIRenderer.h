#pragma once
#include "raylib.h"
#include <memory>
#include "Data.h"
#include "Tutorial.h"

namespace bnc
{

    /// @brief Renders the UI
    class UIRenderer
    {
    public:
        UIRenderer();
        ~UIRenderer();

        /// @brief Renders the UI
        /// @param data pointer to the UIData struct
        void RenderUI(std::shared_ptr<bnc::UIData> data);

    private:
        std::shared_ptr<bnc::UIData> m_UIData;

        uint32_t m_currentText = 0;
        uint32_t m_Timer = 120;
        uint32_t m_PreviousLevel = 0;

        /// @brief Renders the buttons
        void RenderResetButton();
        /// @brief Renders the result on the screen
        void RenderResult();

        void RenderTitle();
        
        void RenderMainMenuBg();

        void RenderSelectMenuBg();

        void RenderMenuButtons();

        void RenderBackButton();

        void RenderLevelSelect();
        /// @brief Renders the tutorial
        void RenderTutorial();
    };
}