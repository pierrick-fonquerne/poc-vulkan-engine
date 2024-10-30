#pragma once
#include <vulkan/vulkan.h>
#include "../Window/Window.h"

class VulkanSurface
{
public:
    void createSurface(VkInstance instance, Window &window);
    void cleanup(VkInstance instance);

private:
    VkSurfaceKHR surface;
};
