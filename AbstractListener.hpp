#pragma once

struct AbstractListener {
    virtual ~AbstractListener() = default;
    virtual char OnKeyPress() = 0;
    virtual bool IsKeyPressed(int key) = 0;
};