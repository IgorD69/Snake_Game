#pragma once
#include "AbstractListener.hpp"

class CmdListener : public AbstractListener {
public:
    CmdListener();
    ~CmdListener() override;
    char OnKeyPress() override;
    bool IsKeyPressed(int key) override;
};
