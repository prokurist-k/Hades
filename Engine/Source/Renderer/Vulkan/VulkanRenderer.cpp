#include "../../Core.h"
#include "Source/Core/Logging/Log.h"
#include "VulkanRenderer.h"
#include <algorithm>
#include <cstdint>
#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_structs.hpp>

namespace Hades
{

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugUtilsCallback(VkDebugUtilsMessageSeverityFlagBitsEXT msg_severity,
    VkDebugUtilsMessageTypeFlagsEXT msgType, const VkDebugUtilsMessengerCallbackDataEXT* callback_data, void* user_data)
{
    if (!callback_data)
    {
        return VK_FALSE;
    }

    if (!callback_data->pMessage)
    {
        return VK_FALSE;
    }

    const bool is_error = (msg_severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) != 0;
    const bool is_warning = (msg_severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) != 0;

    ELogLevel log_level = ELogLevel::Log;
    if (is_error)
    {
        log_level = ELogLevel::Error;
    }
    else if (is_warning)
    {
        log_level = ELogLevel::Warning;
    }
    CLogger::Get().BasicLog(log_level, "[Vulkan]: %s", callback_data->pMessage);

    return VK_FALSE;
}

bool CVulkanRenderer::Initialize()
{
#ifdef HADES_DEBUG
    use_validation_layers = CheckValidationLayerSupport();
    if (!use_validation_layers)
    {
        HADES_LOG(Warning, "Validation layers requested but not available, continuing without them")
    }
#else
    use_validation_layers = false;
#endif

    vk::ApplicationInfo application_info = {};
    application_info.pApplicationName = "Hades";
    application_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    application_info.pEngineName = "Hades";
    application_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    application_info.apiVersion = vk::ApiVersion13;

    vk::InstanceCreateInfo create_info {};
    create_info.pApplicationInfo = &application_info;
    if (use_validation_layers)
    {
        create_info.enabledLayerCount = static_cast<uint32_t>(validation_layers.size());
        create_info.ppEnabledLayerNames = validation_layers.data();
    }
    else
    {
        create_info.enabledLayerCount = 0;
    }

    create_info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    create_info.ppEnabledExtensionNames = extensions.data();

    instance = vk::raii::Instance(context, create_info);

#ifdef HADES_DEBUG
    SetupDebugCallbacks();
#endif

    return true;
};

void CVulkanRenderer::Shutdown()
{
}

void CVulkanRenderer::Render()
{
}
void CVulkanRenderer::Resize(const int width, const int height)
{
}

std::vector<VkLayerProperties> CVulkanRenderer::GetAvailableLayerProperties() const
{
    uint32_t count = 0;
    VkResult result = vkEnumerateInstanceLayerProperties(&count, nullptr);
    if (result != VK_SUCCESS)
    {
        HADES_LOG(Error, "vkEnumerateInstanceLayerProperties (count) failed: %d", static_cast<int>(result))
        return {};
    }

    std::vector<VkLayerProperties> layers(count);
    result = vkEnumerateInstanceLayerProperties(&count, layers.data());
    if (result != VK_SUCCESS && result != VK_INCOMPLETE)
    {
        HADES_LOG(Error, "vkEnumerateInstanceLayerProperties (data) failed: %d", static_cast<int>(result))
        return {};
    }

    layers.resize(count);
    HADES_LOG(Log, "%u available layer properties found", count)
    return layers;
}

bool CVulkanRenderer::CheckValidationLayerSupport() const
{
    const auto available_layers = GetAvailableLayerProperties();
    if (available_layers.empty())
    {
        HADES_LOG(Error, "No instance layers available")
        return false;
    }

    for (const char* wanted : validation_layers)
    {
        auto it = std::find_if(available_layers.begin(), available_layers.end(),
            [&](const VkLayerProperties& p)
            { return std::strcmp(wanted, p.layerName) == 0; });

        if (it == available_layers.end())
        {
            HADES_LOG(Error, "Validation layer '%s' not found", wanted)
            return false;
        }
    }
    return true;
}

void CVulkanRenderer::SetupDebugCallbacks()
{
    vk::DebugUtilsMessengerCreateInfoEXT debug_msg_create_info {};
    debug_msg_create_info.messageSeverity = vk::DebugUtilsMessageSeverityFlagBitsEXT::eError | vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning;
    debug_msg_create_info.messageType = vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance;
    debug_msg_create_info.pfnUserCallback = DebugUtilsCallback;
    debug_msg_create_info.pUserData = nullptr;
    debug_messenger = vk::raii::DebugUtilsMessengerEXT(instance, debug_msg_create_info);
}

}
