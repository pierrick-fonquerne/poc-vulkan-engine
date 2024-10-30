#pragma once
#include <GLFW/glfw3.h>

class Window {
public:
    Window() = default;
    ~Window();

    void create(int width, int height, const char* title);
    void pollEvents() const;
    bool shouldClose() const;

    GLFWwindow* getGLFWWindow() const { return window; }

private:
    GLFWwindow* window = nullptr;

    void initGLFW() const;
    void createWindow(int width, int height, const char* title);
    void cleanup() const;
};
