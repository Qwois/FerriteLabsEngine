#include "Application.h"
#include <stdexcept>
#include <iostream>

namespace Ferrite 
{

Application::Application() = default;
Application::~Application() = default;

int Application::Run() 
{
    InitWindow();
    renderer.Init(window);
    MainLoop();
    Cleanup();
    return 0;
}

void Application::InitWindow() 
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(800, 600, "Ferrite Labs Engine", nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("Failed to create GLFW window");
    }
}

void Application::MainLoop() 
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

void Application::Cleanup() 
{
    renderer.Cleanup();
    glfwDestroyWindow(window);
    glfwTerminate();
}
}