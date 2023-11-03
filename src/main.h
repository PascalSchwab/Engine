#ifndef __MAIN__
#define __MAIN__

#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "opengl.h"
#include "window.h"
#include "iomanager.h"
#include "shader.h"
#include "mesh.h"

#define SUCCESS 0
#define ERROR 1

static int startEngine();

static void update();

static void render();

static void loop();

static void dispose();

#endif