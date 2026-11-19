#pragma once

#include "../Window.h"
#include <X11/Xlib.h>
#include <vector>

namespace Hades
{
class CLinuxWindow : public IWindow
{
public:
    virtual bool Initialize() override;
    virtual void Shutdown() override;

    virtual void Show() override;

    virtual void ProcessEvents(std::vector<Event>& events) override;
    virtual bool IsOpen() const override;

private:
    Display* display;
    Window window;
    bool is_open = false;
    Atom del_window;
};

}
