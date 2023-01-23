#include <iostream>

#include "renderer.hpp"

#include <GLFW/glfw3.h>

int main() {
    renderer r(400, 90);
    r.render();

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

    return 0;
}
