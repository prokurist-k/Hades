#pragma once

namespace Hades
{
class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;

    virtual void Render() = 0;
    virtual void Resize(const int width, const int height) = 0;
};
}
