#ifndef __SHADER__
#define __SHADER__

#include "main.h"

typedef struct{
    unsigned int id;
    unsigned int shaderType;
} Shader;

typedef struct{
    unsigned int id;
} ShaderProgram;

Shader* initShader(int shaderType, const char* source);

ShaderProgram* initProgram(const char* vertexSource, const char* fragmentSource, const char* geometrySource);

void disposeShader(Shader* shader);

void disposeProgram(ShaderProgram* program);

#endif