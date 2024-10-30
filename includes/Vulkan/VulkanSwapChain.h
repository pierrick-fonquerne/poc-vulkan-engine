#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include "../Window/Window.h"
#include "VulkanDevice.h"

class VulkanSwapChain
{
public:
    void createSwapChain(VulkanDevice &device, VkSurfaceKHR surface,
                         Window &window);
    void cleanup(VkDevice device);

private:
    VkSwapchainKHR swapChain = VK_NULL_HANDLE;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(
        const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(
        const std::vector<VkPresentModeKHR> &availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities,
                                Window &window);
};
