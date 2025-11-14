#pragma once

#include "Position.hpp"
#include <vector>
#include <string>

using Image = std::vector<std::string>;

struct AbstractRenderer
{
   virtual ~AbstractRenderer() = default;

   virtual void ClearScreen() = 0;
   virtual void DrawImage(Position topLeft, Position bottomRight, const Image& image) = 0;
   virtual void WriteText(Position position, const std::string& text) = 0;
};
