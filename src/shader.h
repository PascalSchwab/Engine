#ifndef __SHADER__
#define __SHADER__

#include "main.h"

typedef struct{
    unsigned int id;
    unsigned int shaderType;
} Shader;

typedef struct{
    unsigned int id;
    File* vertexShaderFile;
    File* fragmentShaderFile;
    File* geometryShaderFile;
} ShaderProgram;

Shader* initShader(int shaderType, const char* source);

ShaderProgram* initProgram(char* vertexShaderPath, char* fragmentShaderPath, char* geometryShaderPath);

void disposeShader(Shader* shader);

void disposeProgram(ShaderProgram* program);

#endif