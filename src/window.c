#include "window.h"

Window* initWindow(int width, int height, char* title, int resizable){
    // Init Window
    Window* window = malloc(sizeof(Window));
    window->width = width;
    window->height = height;
    window->title = title;
    window->resizable = resizable;

    // Set Window Options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if(!resizable){
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    }

    // Check gl_window creation
    GLFWwindow* glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
    if (glfwWindow == NULL)
    {
        printf("Failed to create GLFW window");
        return NULL;
    }
    glfwMakeContextCurrent(glfwWindow);
    window->window = glfwWindow;

    // Check working glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return NULL;
    }

    glViewport(0, 0, width, height);
    return window;
}

void disposeWindow(Window* window){
    glfwDestroyWindow(window->window);
    free(window);
}