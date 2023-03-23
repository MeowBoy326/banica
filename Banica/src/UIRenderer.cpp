#include "UIRenderer.h"


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
        GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

        if(m_UIData->isResetButtonPressed != nullptr)
            *m_UIData->isResetButtonPressed = GuiButton(Rectangle({20.0f, GetScreenHeight() - 70.0f, 220.0f, 60.0f}), "RESET LEVEL");
    }

    void UIRenderer::RenderUI(std::shared_ptr<bnc::UIData> data)
    {
        m_UIData = data;

        RenderButtons();
    }
}