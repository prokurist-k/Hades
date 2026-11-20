#include "../Renderer.h"
#include <vector>
#include <vulkan/vulkan_raii.hpp>

namespace Hades
{
class CVulkanRenderer : public IRenderer
{
public:
    virtual bool Initialize() override;
    virtual void Shutdown() override;
    virtual void Render() override;
    virtual void Resize(const int width, const int height) override;

private:
    std::vector<VkLayerProperties> GetAvailableLayerProperties() const;
    bool CheckValidationLayerSupport() const;

    void SetupDebugCallbacks();

private:
    vk::raii::Context context {};
    vk::raii::Instance instance = nullptr;
    vk::raii::DebugUtilsMessengerEXT debug_messenger = nullptr;

    bool use_validation_layers = false;

    const std::vector<const char*> validation_layers = {
        "VK_LAYER_KHRONOS_validation",
    };

    const std::vector<const char*> extensions = {
        VK_EXT_DEBUG_UTILS_EXTENSION_NAME
    };
};
}
