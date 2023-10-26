#include "window.h"

GLFWwindow* initWindow(const int width, const int height, const char* title, const int resizable){
    // Set Window Options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if(!resizable){
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    }

    // Check window creation
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (window == NULL)
    {
        printf("Failed to create GLFW window");
        return NULL;
    }

    glfwMakeContextCurrent(window);

    // Check working glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return NULL;
    }

    glViewport(0, 0, width, height);
    return window;
}

