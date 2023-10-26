#ifndef __SHADER__
#define __SHADER__

#include "main.h"

glId initShader(const int shaderType, const char* source);

glId initProgram(const char* vertexSource, const char* fragmentSource, const char* geometrySource);

void disposeProgram();

#endif