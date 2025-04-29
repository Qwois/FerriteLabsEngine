#pragma once

#include "Window.h"
#include <memory>
#include "VulkanRenderer.h"

namespace Ferrite
{
class Application
{
public:
    Application();
    ~Application();

    int Run();

private:
    void Init();
    void MainLoop();
    void Cleanup();

    std::unique_ptr<Window> window;
    VulkanRenderer renderer;
};
}
