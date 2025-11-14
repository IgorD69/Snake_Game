#pragma once

#include "Abstract_Renderer.hpp"
#include "Position.hpp"


class Renderer : public AbstractRenderer
{
public:
    Renderer() = default;
    virtual ~Renderer() = default;

    void Init();
    void SetBackgroundColor(int r, int g, int b);
    void SetForegroundColor(int r, int g, int b);
    void PutText(Position position, char* text);
    void PutBox(int x, int y, int width, int height);
    virtual void ClearScreen() override;
    virtual void DrawImage(Position topLeft, Position bottomRight, const Image& image) override;
    virtual void WriteText(Position position, const std::string& text) override;
};
