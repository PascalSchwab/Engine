#include "shader.h"

glId initShader(const int shaderType, const char* source){
    glId shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    return shader;
}

glId initProgram(const char* vertexSource, const char* fragmentSource, const char* geometrySource){
        // Vertex and Fragment shader are required
    if(vertexSource == NULL){
        printf("Vertex Shader is not defined");
        return ERROR;
    }
    if(fragmentSource == NULL){
        printf("Fragment Shader is not defined");
        return ERROR;
    }
    
    glId program = glCreateProgram();

    // Init shaders
    glId vertexShader = initShader(GL_VERTEX_SHADER, vertexSource);
    glAttachShader(program, vertexShader);
    glId fragmentShader = initShader(GL_FRAGMENT_SHADER, fragmentSource);
    glAttachShader(program, fragmentShader);
    unsigned int geometryShader;
    if(geometrySource != NULL){
        geometryShader = initShader(GL_GEOMETRY_SHADER, geometrySource);
        glAttachShader(program, geometryShader);
    }

    // Link shaders
    glLinkProgram(program);

    // Delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if(geometrySource != NULL){
        glDeleteShader(geometryShader);
    }

    return program;
}