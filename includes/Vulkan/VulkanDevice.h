#pragma once
#include <vulkan/vulkan.h>
#include <optional>
#include <vector>
#include "VulkanInstance.h"

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() const
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

class VulkanDevice
{
public:
    VulkanDevice();

    void pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);
    void createLogicalDevice();

    VkDevice getDevice() const { return device; }
    VkPhysicalDevice getPhysicalDevice() const { return physicalDevice; }
    VkQueue getGraphicsQueue() const { return graphicsQueue; }
    VkQueue getPresentQueue() const { return presentQueue; }

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    void cleanup();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

private:
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    VkQueue graphicsQueue = VK_NULL_HANDLE;
    VkQueue presentQueue = VK_NULL_HANDLE;

    VkInstance instance = VK_NULL_HANDLE;

    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    const std::vector<const char *> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
};
