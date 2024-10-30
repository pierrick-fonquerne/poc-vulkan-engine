#include "Vulkan/VulkanSurface.h"
#include <stdexcept>

void VulkanSurface::createSurface(VkInstance instance, Window &window)
{
    if (glfwCreateWindowSurface(instance, window.getGLFWWindow(), nullptr, &surface) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create window surface!");
    }
}

void VulkanSurface::cleanup(VkInstance instance)
{
    vkDestroySurfaceKHR(instance, surface, nullptr);
}
