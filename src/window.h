#ifndef __WINDOW__
#define __WINDOW__

#include "main.h"

typedef struct{
    unsigned int width;
    unsigned int height;
    char* title;
    unsigned int resizable;
    GLFWwindow* window;
} Window;

Window* initWindow(int width, int height, char* title, int resizable);

void disposeWindow(Window* window);

#endif