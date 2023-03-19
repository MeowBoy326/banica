#pragma once
#include "raylib.h"
#include <memory>
#include "UIData.h"

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

        void RenderButtons();    
    };
}