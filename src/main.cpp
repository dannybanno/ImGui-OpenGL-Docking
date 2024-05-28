#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "gui/gui.h"

int screenWidth = 1920;
int screenHeight = 1080;


GLFWwindow* window;

int main() {

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(screenWidth, screenHeight, "OpenGL ImGui Docking", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        return -1;
    }

    initImGui(window);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glViewport(0, 0, screenWidth, screenHeight);

        renderImGui();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    shutdownImGui();

    glfwTerminate();

    return 0;
}
