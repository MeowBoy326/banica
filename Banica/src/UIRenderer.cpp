#include "UIRenderer.h"
#include <iostream>


#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace bnc
{
    UIRenderer::UIRenderer()
    {

    }

    UIRenderer::~UIRenderer()
    {

    }

    void UIRenderer::RenderButtons()
    {
        GuiSetFont(m_UIData->mainFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

        m_UIData->isResetButtonPressed = GuiButton(Rectangle({GetScreenWidth() - 240.0f, GetScreenHeight() - 70.0f, 220.0f, 60.0f}), "RESET LEVEL");
    }

    void UIRenderer::RenderResult()
    {
        Vector2 position = {GetScreenWidth() - (m_UIData->p_Result->size() * 60) - 100.0f, (GetScreenHeight() / 2)};

        DrawTextEx(m_UIData->mainFont, "RESULT",
         Vector2({position.x + 60, position.y - 60}), 
         36, 2, RAYWHITE);

        for(size_t i = 0; i < m_UIData->p_Result->size(); i++)
        {
            if(m_UIData->p_Result->operator[](i) == '1')
            {
                DrawTextureRec(
                    m_UIData->spriteTexture,
                    Rectangle({0, 60.0f, 60.0f, 60.0f}),
                    position,
                    RAYWHITE
                );
            }
            else
            {
                DrawTextureRec(
                    m_UIData->spriteTexture,
                    Rectangle({60.0f, 60.0f, 60.0f, 60.0f}),
                    position,
                    RAYWHITE
                );
            }

            position.x += 60;
        }
    }

    void UIRenderer::RenderTutorial()
    {
       if(m_PreviousLevel != *m_UIData->currentLevel)
       {
            m_currentText = 0;
            m_Timer = 120;
            m_PreviousLevel++;
       }

        if(!m_UIData->skipTutorial)
        {
            bnc::renderTutorial(m_UIData, m_currentText, m_Timer);

            DrawTextEx(m_UIData->mainFont, "PRESS C TO SKIP", Vector2({700.0f, (GetScreenHeight() - 660.0f) / 2}), 16, 2, RAYWHITE);
        }
        else
        {
            m_currentText = 0;
        }
    }

    void UIRenderer::RenderUI(std::shared_ptr<bnc::UIData> data)
    {
        m_UIData = data;

        RenderButtons();
        RenderResult();
        RenderTutorial();
    }
}