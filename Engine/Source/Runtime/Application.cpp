// Application.cpp
#include "Application.h"
#include <spdlog/spdlog.h>

namespace Ferrite
{
Application::Application() = default;
Application::~Application() = default;

int Application::Run()
{
    try {
        Init();
        MainLoop();
        Cleanup();
    } catch (const std::exception& e) {
        spdlog::error("Fatal error: {}", e.what());
        return -1;
    }
    return 0;
}

void Application::Init()
{
    spdlog::set_level(spdlog::level::debug); // можно менять на info
    spdlog::info("Initializing application...");

    window = std::make_unique<Window>(1280, 720, "Ferrite Labs Engine");

    window->SetResizeCallback([](int width, int height) {
        spdlog::info("Window resized: {}x{}", width, height);
    });

    renderer.Init(window->GetNativeHandle());

    spdlog::info("Initialization complete.");
}

void Application::MainLoop()
{
    while (!window->ShouldClose()) {
        window->PollEvents();

        // Update, Render и т.п. — позже сюда
    }
}

void Application::Cleanup()
{
    renderer.Cleanup();
    window.reset();
    spdlog::info("Application cleanup complete.");
}
}
