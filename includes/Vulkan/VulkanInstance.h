#pragma once
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

class VulkanInstance {
public:
    VulkanInstance() = default;
    ~VulkanInstance();

    void createInstance();
    void createSurface(GLFWwindow* window);

    VkInstance getInstance() const { return instance; }
    VkSurfaceKHR getSurface() const { return surface; }

private:
    VkInstance instance = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;

    void cleanup();
};
