#pragma once
#include "Abstract_Renderer.hpp"

class Renderer : public AbstractRenderer {
public:
    Renderer() = default;
    ~Renderer() override = default;

    void ClearScreen() override;
    void DrawImage(Position topLeft, Position bottomRight, const Image& image) override;
    void WriteText(Position position, const std::string& text) override;
};
