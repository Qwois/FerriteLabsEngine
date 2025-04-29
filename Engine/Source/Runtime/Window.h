#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <functional>
#include <glm/vec2.hpp>

namespace Ferrite
{
class Window
{
public:
    using ResizeCallback = std::function<void(int width, int height)>;

    Window(int width, int height, const std::string& title);
    ~Window();

    void PollEvents() const;
    bool ShouldClose() const;
    void SetResizeCallback(ResizeCallback callback);
    glm::ivec2 GetFramebufferSize() const;
    GLFWwindow* GetNativeHandle() const { return window; }

    ResizeCallback resizeCallback;

private:
    GLFWwindow* window = nullptr;
};
}
