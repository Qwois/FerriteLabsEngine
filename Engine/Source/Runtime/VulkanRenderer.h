#pragma once

#define VK_NO_PROTOTYPES
#include <volk.h>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <vector>

namespace Ferrite 
{

class VulkanRenderer 
{
public:
    void Init(GLFWwindow* window);
    void Cleanup();
    void OnResize(int width, int height);

private:
    void CreateInstance();
    void CreateSurface(GLFWwindow* window);

    void PickPhysicalDevice();
    
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkInstance instance = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;

    VkFormat swapchainImageFormat;
    VkExtent2D swapchainExtent;
    std::vector<VkImage> swapchainImages;
    std::vector<VkImageView> swapchainImageViews;

    void CreateSwapchain(uint32_t width, uint32_t height);
    void CleanupSwapchain();
};
}
