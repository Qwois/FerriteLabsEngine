#pragma once

#include <GLFW/glfw3.h>
#include "VulkanRenderer.h"

namespace Ferrite {

class Application {
public:
    Application();
    ~Application();

    int Run();

private:
    void InitWindow();
    void MainLoop();
    void Cleanup();

    GLFWwindow* window = nullptr;
    VulkanRenderer renderer;
};

}
