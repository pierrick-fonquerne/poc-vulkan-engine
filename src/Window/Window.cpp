#include "Window/Window.h"
#include <stdexcept>

Window::~Window() {
    cleanup();
}

void Window::create(int width, int height, const char* title) {
    initGLFW();
    createWindow(width, height, title);
}

void Window::initGLFW() const {
    if (!glfwInit()) {
        throw std::runtime_error("Échec de l'initialisation de GLFW");
    }
}

void Window::createWindow(int width, int height, const char* title) {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("Échec de la création de la fenêtre");
    }
}

void Window::pollEvents() const {
    glfwPollEvents();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::cleanup() const {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}
