#pragma once

#include "../Window/Window.h"
#include "../Vulkan/VulkanInstance.h"
#include "../Vulkan/VulkanSwapChain.h"
#include "../Vulkan/VulkanDevice.h"

class VulkanApp
{
public:
    VulkanApp();
    void run();
    void initVulkan();
    void cleanup();

private:
    Window window;
    VulkanInstance instance;
    VulkanDevice device;
    VulkanSwapChain swapChain;
};
