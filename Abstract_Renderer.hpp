#pragma once

#include "Position.hpp"
#include <vector>
#include <string>

using GameImage = std::vector<std::string>;  // Changed from Image to GameImage

struct AbstractRenderer
{
   virtual ~AbstractRenderer() = default;

   virtual void ClearScreen() = 0;
   virtual void DrawImage(Position topLeft, Position bottomRight, const GameImage& image) = 0;  // Changed here
   virtual void WriteText(Position position, const std::string& text) = 0;
};
