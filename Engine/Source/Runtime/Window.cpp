#include "Window.h"
#include <stdexcept>
#include <spdlog/spdlog.h>

namespace Ferrite
{
static void GLFWResizeCallback(GLFWwindow* win, int width, int height)
{
    auto userPtr = static_cast<Window*>(glfwGetWindowUserPointer(win));
    if (userPtr && userPtr->resizeCallback)
        userPtr->resizeCallback(width, height);
}

Window::Window(int width, int height, const std::string& title)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
        throw std::runtime_error("Failed to create GLFW window");

    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, GLFWResizeCallback);

    spdlog::info("Window created: {}x{}", width, height);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
    spdlog::info("Window destroyed and GLFW terminated.");
}

void Window::PollEvents() const
{
    glfwPollEvents();
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(window);
}

void Window::SetResizeCallback(ResizeCallback callback)
{
    resizeCallback = callback;
}

glm::ivec2 Window::GetFramebufferSize() const
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    return {width, height};
}
}