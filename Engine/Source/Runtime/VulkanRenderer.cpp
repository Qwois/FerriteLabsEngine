#include "VulkanRenderer.h"
#include <stdexcept>
#include <iostream>

namespace Ferrite 
{

void VulkanRenderer::Init(GLFWwindow* window) 
{
    if (volkInitialize() != VK_SUCCESS) 
    {
        throw std::runtime_error("Failed to initialize volk");
    }

    CreateInstance();
    volkLoadInstance(instance);

    CreateSurface(window);

    std::cout << "Vulkan initialized successfully!" << std::endl;
}

void VulkanRenderer::CreateInstance() 
{
    VkApplicationInfo appInfo{ VK_STRUCTURE_TYPE_APPLICATION_INFO };
    appInfo.pApplicationName = "Ferrite Labs Engine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Ferrite Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_3;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    VkInstanceCreateInfo createInfo{ VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) 
    {
        throw std::runtime_error("Failed to create Vulkan instance");
    }
}

void VulkanRenderer::CreateSurface(GLFWwindow* window) 
{
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) 
    {
        throw std::runtime_error("Failed to create window surface");
    }
}

void VulkanRenderer::Cleanup() 
{
    if (surface != VK_NULL_HANDLE) 
    {
        vkDestroySurfaceKHR(instance, surface, nullptr);
    }
    if (instance != VK_NULL_HANDLE) 
    {
        vkDestroyInstance(instance, nullptr);
    }
}
}
