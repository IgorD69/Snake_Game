#pragma once

#include "Position.hpp"

struct AbstractRenderer
{
   virtual void DrawImage(Position topLeft, Position bottomRight, char** image) = 0;
   virtual void WriteText(Position position, char* text) = 0;
};
