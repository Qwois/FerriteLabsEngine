cmake_minimum_required(VERSION 3.20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
endif()

project(FerriteLabsEngine LANGUAGES CXX)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake" CACHE FILEPATH "")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)




include(${CMAKE_TOOLCHAIN_FILE})
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)
find_package(EnTT REQUIRED)
find_package(yaml-cpp REQUIRED)

find_package(Vulkan REQUIRED)
find_package(volk REQUIRED)
find_package(SPIRV-Headers REQUIRED)

find_package(nuklear REQUIRED)




add_executable(EngineMain
    Engine/Source/Runtime/Application.cpp
    Engine/Source/Runtime/VulkanRenderer.cpp
    Engine/Source/Runtime/Window.cpp
    Engine/Source/Runtime/Launch/LaunchWindows.cpp
)

target_include_directories(EngineMain PUBLIC
    ${CMAKE_SOURCE_DIR}/Engine/Source/Runtime
)

target_link_libraries(EngineMain PUBLIC
    glfw
    glm::glm
    spdlog::spdlog
    EnTT::EnTT
    yaml-cpp
    Vulkan::Vulkan
    volk::volk
    SPIRV-Headers::SPIRV-Headers
    nuklear::nuklear
)


set_target_properties(EngineMain PROPERTIES
    WIN32_EXECUTABLE YES
)