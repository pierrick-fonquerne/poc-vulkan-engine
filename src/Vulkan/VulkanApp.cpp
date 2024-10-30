#include <iostream>
#include "Vulkan/VulkanApp.h"

VulkanApp::VulkanApp()
{
}

void VulkanApp::run()
{
    window.createWindow(800, 600, "Vulkan Window");

    try
    {
        initVulkan();

        while (!glfwWindowShouldClose(window.getGLFWWindow()))
        {
            glfwPollEvents();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        cleanup();
        
        return;
    }

    cleanup();
}

void VulkanApp::initVulkan()
{
    instance.createInstance();
    instance.createSurface(window.getGLFWWindow());
    device.pickPhysicalDevice(instance.getInstance(), instance.getSurface());
    device.createLogicalDevice();
    swapChain.createSwapChain(device, instance.getSurface(), window);
}

void VulkanApp::cleanup()
{
    swapChain.cleanup(device.getDevice());
    device.cleanup();
    instance.cleanup();
    window.cleanup();
}
