#include "../PlatformUtils.h"
#include "LinuxWindow.h"
#include "Source/Core/Logging/Log.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <vector>

namespace Hades
{
bool CLinuxWindow::Initialize()
{
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        HADES_LOG(Error, "Failed to create Display")
        return false;
    }
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, 1024, 756, 1, BlackPixel(display, 0), WhitePixel(display, 0));

    XSelectInput(display, window, ExposureMask | StructureNotifyMask | KeyPressMask | KeyReleaseMask);
    del_window = XInternAtom(display, "WM_DELETE_WINDOW", 0);
    XSetWMProtocols(display, window, &del_window, 1);
    return true;
}

void CLinuxWindow::Shutdown()
{
    is_open = false;
    if (display)
    {
        XDestroyWindow(display, window);
        XCloseDisplay(display);
    }
}

void CLinuxWindow::Show()
{
    XMapWindow(display, window);
    XFlush(display);
    is_open = true;
}

void CLinuxWindow::ProcessEvents(std::vector<Event>& events)
{
    while (XPending(display) > 0)
    {
        XEvent event;
        XNextEvent(display, &event);
        switch (event.type)
        {
        case ClientMessage:
            if (event.xclient.data.l[0] == del_window)
            {
                events.push_back(SWindowCloseRequested {});
            }
            break;
        case MapNotify:
            HADES_LOG(Log, "Window mapped: %u", window)
            is_open = true;
            break;
        case KeyPress:
            events.push_back(SKeyPressed { CPlatformUtils::TranslateKeyCode(event.xkey.keycode), false });
            break;
        case KeyRelease:
            events.push_back(SKeyReleased { CPlatformUtils::TranslateKeyCode(event.xkey.keycode) });
            break;
        }
    }
}

bool CLinuxWindow::IsOpen() const
{
    return is_open;
}
}
