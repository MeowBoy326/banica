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

    void UIRenderer::RenderResetButton()
    {
        GuiSetFont(m_UIData->mainFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

        m_UIData->isResetButtonPressed = GuiButton(Rectangle({GetScreenWidth() - 240.0f, GetScreenHeight() - 150.0f, 220.0f, 60.0f}), "RESET LEVEL");
    }

    void UIRenderer::RenderResult()
    {
        Vector2 position = {GetScreenWidth() - (m_UIData->p_Result->size() * 60) - 100.0f, (GetScreenHeight() / 2)};

        DrawTextEx(m_UIData->mainFont, "RESULT",
         Vector2({position.x + 60, position.y - 60}), 
         36, 2, WHITE);

        for(size_t i = 0; i < m_UIData->p_Result->size(); i++)
        {
            if(m_UIData->p_Result->operator[](i) == '1')
            {
                DrawTextureRec(
                    m_UIData->spriteTexture,
                    Rectangle({0, 60.0f, 60.0f, 60.0f}),
                    position,
                    WHITE
                );
            }
            else
            {
                DrawTextureRec(
                    m_UIData->spriteTexture,
                    Rectangle({60.0f, 60.0f, 60.0f, 60.0f}),
                    position,
                    WHITE
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

            DrawTextEx(m_UIData->mainFont, "PRESS C TO SKIP", Vector2({700.0f, (GetScreenHeight() - 660.0f) / 2.0f}), 16, 2, WHITE);
        }
        else
        {
            m_currentText = 0;
        }
    }

    void UIRenderer::RenderTitle()
    {
        DrawTextEx(m_UIData->mainFont, "BANICA", Vector2({(GetScreenWidth() / 2.0f) + 2.0f - MeasureTextEx(m_UIData->mainFont, "BANICA", 50, 2).x / 2.0f, GetScreenHeight() / 5.0f + 2.0f}), 50, 2, BLACK);

        DrawTextEx(m_UIData->mainFont, "BANICA", Vector2({(GetScreenWidth() / 2.0f) - MeasureTextEx(m_UIData->mainFont, "BANICA", 50, 2).x / 2.0f, GetScreenHeight() / 5.0f}), 50, 2, WHITE);
        
    }

    void UIRenderer::RenderMenuButtons()
    {
        GuiSetFont(m_UIData->mainFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 50);
        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, 0xFFFFFFFF);
        GuiSetStyle(DEFAULT, TEXT_COLOR_FOCUSED, 0xA6A6A6FF);
        GuiSetStyle(DEFAULT, TEXT_COLOR_PRESSED, 0x666666FF);

        m_UIData->isPlayButtonPressed = GuiLabelButton(Rectangle({(GetScreenWidth() / 2.0f) - MeasureTextEx(m_UIData->mainFont, "PLAY", 50, 2).x / 2.0f, (GetScreenHeight() / 2.0f) - 35.0f, MeasureTextEx(m_UIData->mainFont, "PLAY", 50, 2).x, 30.0f}), "PLAY");

        m_UIData->isQuitButtonPressed = GuiLabelButton(Rectangle({(GetScreenWidth() / 2.0f) - MeasureTextEx(m_UIData->mainFont, "QUIT", 50, 2).x / 2.0f, (GetScreenHeight() / 2.0f + 55.0f) - 35.0f, MeasureTextEx(m_UIData->mainFont, "QUIT", 50, 2).x, 30.0f}), "QUIT");
    }

    void UIRenderer::RenderMainMenuBg()
    {
        DrawTexture(m_UIData->mainMenuBg, 0, 0, WHITE);
    }

    void UIRenderer::RenderSelectMenuBg()
    {
        DrawTexture(m_UIData->LevelSelectMenuBg, 0, 0, WHITE);
    }

    void UIRenderer::RenderLevelSelect()
    {
        DrawTextEx(m_UIData->mainFont, "LEVELS", Vector2({(GetScreenWidth()/2.0f)-(MeasureTextEx(m_UIData->mainFont, "LEVELS", 42, 2).x/2.0f), GetScreenHeight()/30.0f}), 42, 2, WHITE);

        GuiSetFont(m_UIData->mainFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 50);
        
        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, 0xFFFFFFFF);
        GuiSetStyle(DEFAULT, TEXT_COLOR_FOCUSED, 0xFFFFFFFF);
        GuiSetStyle(DEFAULT, TEXT_COLOR_PRESSED, 0xFFFFFFFF);
        GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);

        for(uint32_t i = 0; i < 8; i++)
        {
            GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, 0x2A2A47FF);
            GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, 0x424470FF);
            GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, 0x9FA0C6FF);
            // if(m_UIData->levels->operator[](*m_UIData->currentLevel)->isCompleted)
            // {
            //     GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, 0x2A4732FF);
            //     GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, 0x42704FFF);
            //     GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, 0x9FC6AAFF);
            // }
            // else
            // {
            //     GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, 0x2A2A47FF);
            //     GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, 0x424470FF);
            //     GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, 0x9FA0C6FF);
            // }
            
            if(i < 4)
            {
                m_UIData->levelSelected[i] = GuiButton(Rectangle({GetScreenWidth()/2.0f - (80*2.0f) + (80*i), GetScreenHeight()/3.5f, 60.0f, 60.0f}), TextFormat("%d", i+1));
            }
            else
            {
                m_UIData->levelSelected[i] = GuiButton(Rectangle({GetScreenWidth()/2.0f - (80*2.0f) + (80*(i-4)), GetScreenHeight()/3.5f + 100.0f, 60.0f, 60.0f}), TextFormat("%d", i+1));
            }
        }
    }

    void UIRenderer::RenderBackButton()
    {

        GuiSetFont(m_UIData->mainFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

        m_UIData->isBackButtonPressed = GuiButton(Rectangle({GetScreenWidth() - 240.0f, GetScreenHeight() - 70.0f, 220.0f, 60.0f}), "BACK");
    }

    void UIRenderer::RenderUI(std::shared_ptr<bnc::UIData> data)
    {
        
        m_UIData = data;

        switch(*m_UIData->gameState)
        {
            case bnc::MAIN_MENU:
                RenderMainMenuBg();
                RenderTitle();
                RenderMenuButtons();
                break;

            case bnc::OPTIONS:
                RenderMainMenuBg();
                RenderTitle();
                RenderMenuButtons();
                break;

            case bnc::LEVEL_SELECT:
                RenderSelectMenuBg();
                RenderLevelSelect();
                RenderBackButton();
                break;

            case bnc::TUTORIAL:
                RenderTutorial();
                RenderBackButton();
                RenderResult();
                break;

            case bnc::GAME:
                RenderResetButton();
                RenderBackButton();
                RenderResult();
                break;
        }
    }
}