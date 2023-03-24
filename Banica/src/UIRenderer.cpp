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

    void UIRenderer::RenderUI(std::shared_ptr<bnc::UIData> data)
    {
        m_UIData = data;

        RenderButtons();
        RenderResult();
    }
}