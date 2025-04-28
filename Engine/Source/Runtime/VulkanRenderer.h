#pragma once

#define VK_NO_PROTOTYPES
#include <volk.h>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

namespace Ferrite {

class VulkanRenderer {
public:
    void Init(GLFWwindow* window);
    void Cleanup();

private:
    void CreateInstance();
    void CreateSurface(GLFWwindow* window);

    VkInstance instance = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
};

}
