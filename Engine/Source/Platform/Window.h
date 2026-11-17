#pragma once

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;

    virtual void Show() = 0;

    virtual void ProcessEvents() = 0;
    virtual bool IsOpen() const = 0;
};
