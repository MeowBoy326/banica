#pragma once 
#include "raylib.h"
#include "Data.h"

namespace bnc
{
   /// @brief Renders the tutorial for the levels that require it
   /// @param data Reference to the UIData struct
   /// @param currentText Reference to the current state of the text
   /// @param timer Reference to a unsigned int storing the duration of the text on the screen
   void renderTutorial(std::shared_ptr<bnc::UIData>& data, uint32_t& currentText, uint32_t& timer); 
}