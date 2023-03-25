#pragma once
#include "raylib.h"
#include <memory>
#include "Data.h"
#include "Tutorial.h"

namespace bnc
{
    class UIRenderer
    {
    public:
        UIRenderer();
        ~UIRenderer();

        void RenderUI(std::shared_ptr<bnc::UIData> data);

    private:
        std::shared_ptr<bnc::UIData> m_UIData;

        uint32_t m_currentText = 0;
        uint32_t m_Timer = 120;
        uint32_t m_PreviousLevel = 0;


        void RenderButtons();    
        void RenderResult();
        void RenderTutorial();
    };
}