#include "AbstractListener.hpp"

class CmdListener : public AbstractListener {
public:
    ~CmdListener() override = default;
    char OnKeyPress() override;
    bool IsKeyPressed(int key) override;
};