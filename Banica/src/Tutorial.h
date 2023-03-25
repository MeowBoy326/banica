#pragma once 
#include "raylib.h"
#include "Data.h"

namespace bnc
{
   void renderTutorial(std::shared_ptr<bnc::UIData>& data, uint32_t& currentText, uint32_t& timer); 
}