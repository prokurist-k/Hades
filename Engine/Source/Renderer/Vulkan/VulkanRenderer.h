#include "../Renderer.h"

class CVulkanRenderer : public IRenderer
{
public:
    virtual bool Initialize() override
    {
        return true;
    };
    virtual void Shutdown() override
    {
    }

    virtual void Render() override
    {
    }
    virtual void Resize(const int width, const int height) override
    {
    }
};
