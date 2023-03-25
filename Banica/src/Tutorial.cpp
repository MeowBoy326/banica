#include "Tutorial.h"

namespace bnc
{
    void renderTutorial(std::shared_ptr<bnc::UIData>& data, uint32_t& currentText, uint32_t& timer)
    {

        switch(*data->currentLevel)
        {
            case 0:
                if(currentText == 0)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THIS IS A GATE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THIS IS A GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }


                if(currentText == 1)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "AND MORE SPECIFICALLY", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "AND MORE SPECIFICALLY", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 2)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "AN AND GATE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "AN AND GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 3)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THERE ARE FOUR TYPES OF GATES", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THERE ARE FOUR TYPES OF GATES", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 4)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "AND GATE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "AND GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 5)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "OR GATE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "OR GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        DrawTextureRec(
                            data->spriteTexture,
                            Rectangle({60.0f, 60.0f * 2, 60.0f, 60.0f}),
                            data->m_FirstGatePosition,
                            RAYWHITE
                        );

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 6)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "XOR GATE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "XOR GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        DrawTextureRec(
                            data->spriteTexture,
                            Rectangle({60.0f * 3, 60.0f * 2, 60.0f, 60.0f}),
                            data->m_FirstGatePosition,
                            RAYWHITE
                        );

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 7)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "NOT GATE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "NOT GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        DrawTextureRec(
                            data->spriteTexture,
                            Rectangle({60.0f * 2, 60.0f * 2, 60.0f, 60.0f}),
                            data->m_FirstGatePosition,
                            RAYWHITE
                        );

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 8)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "EACH GATE AFFECTS", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "EACH GATE AFFECTS", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 9)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THE OUTPUT IN A DIFFERENT WAY", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THE OUTPUT IN A DIFFERENT WAY", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 10)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THE AND GATE IS", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THE AND GATE IS", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 11)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "LIKE MULTIPLICATION", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "LIKE MULTIPLICATION", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 12)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "1 AND 0 EQUALS 0", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "1 AND 0 EQUALS 0", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 13)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "BUT 1 AND 1 EQUALS 1", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "BUT 1 AND 1 EQUALS 1", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 14)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "ALL GATES CAN BE PUSHED", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "ALL GATES CAN BE PUSHED", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 15)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THE GOAL OF THE GAME", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THE GOAL OF THE GAME", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 16)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "PLACE ALL GATES", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "PLACE ALL GATES", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 17)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "IN THE RIGHT PLACE", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "IN THE RIGHT PLACE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }
                
                if(currentText == 18)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "SO THAT IT IS EQUAL", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "SO THAT IT IS EQUAL", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 19)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "TO THE RESULT", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "TO THE RESULT", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 20)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "SIMPLE... RIGHT?", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "SIMPLE... RIGHT?", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                break;
            case 1:
                if(currentText == 0)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THE OR GATE IS", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THE OR GATE IS", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 1)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "LIKE ADDITION", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "LIKE ADDITION", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 2)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "1 AND 0 EQUALS 1", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "1 AND 0 EQUALS 1", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 3)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "1 AND 1 EQUALS 1", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "1 AND 1 EQUALS 1", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 4)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "BUT 0 AND 0 EQUALS 0", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "BUT 0 AND 0 EQUALS 0", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                break;

            case 2:
                if(currentText == 0)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THE XOR GATE IS", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "THE XOR GATE IS", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 1)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "A BIT MORE INTERESTING", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "A BIT MORE INTERESTING", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 2)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "TO GET 1 BOTH SIDES", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "TO GET 1 BOTH SIDES", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 3)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "MUST BE DIFFERENT", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "MUST BE DIFFERENT", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 4)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "1 AND 1 EQUALS 0", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "1 AND 1 EQUALS 0", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 5)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "BUT 1 AND 0 EQUALS 1", Vector2({35.0f + (660.0f / 2) - (MeasureTextEx(data->mainFont, "BUT 1 AND 0 EQUALS 0", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                break;

            case 3:
                if(currentText == 0)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "THE NOT GATE IS", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "THE NOT GATE IS", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 1)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "IS TOTALLY DIFFERENT", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "IS TOTALLY DIFFERENT", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 2)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "IT MUST BE USED", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "IT MUST BE USED", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 3)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "IN COLLABORATION WITH", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "IN COLLABORATION WITH", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 4)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "ANOTHER GATE", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "ANOTHER GATE", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 5)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "AND IT INVERTS THE OUTPUT", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "AND IT INVERTS THE OUTPUT", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                if(currentText == 6)
                {
                    if(timer != 0)
                    {
                        DrawTextEx(data->mainFont, "SO 1111 BECOMES 0000", Vector2({35.0f + (720.0f / 2) - (MeasureTextEx(data->mainFont, "SO 1111 BECOMES 0000", 36, 2).x / 2), float(GetScreenHeight() / 2) - 75}), 36, 2, RAYWHITE);

                        timer--;
                    }
                    else
                    {
                        timer = 120;
                        currentText++;
                    }
                }

                break;
        }

    }
}