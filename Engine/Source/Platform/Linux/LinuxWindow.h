#pragma once

#include "../Window.h"
#include <X11/Xlib.h>

class CLinuxWindow : public IWindow
{
public:
    virtual bool Initialize() override;
    virtual void Shutdown() override;

    virtual void Show() override;

    virtual void ProcessEvents() override;
    virtual bool IsOpen() const override;

private:
    Display* display;
    Window window;
    bool is_open = false;
    Atom del_window;
};
