#include "shader.h"

Shader* initShader(int shaderType, const char* source){
    Shader* shader = malloc(sizeof(Shader));
    shader->shaderType = shaderType;
    shader->id = glCreateShader(shaderType);
    glShaderSource(shader->id, 1, &source, NULL);
    glCompileShader(shader->id);
    return shader;
}

ShaderProgram* initProgram(const char* vertexSource, const char* fragmentSource, const char* geometrySource){
    ShaderProgram* program = malloc(sizeof(ShaderProgram));

    // Vertex and Fragment shader are required
    if(vertexSource == NULL){
        printf("Vertex Shader is not defined");
        return NULL;
    }
    if(fragmentSource == NULL){
        printf("Fragment Shader is not defined");
        return NULL;
    }
    
    program->id = glCreateProgram();

    // Init shaders
    Shader* vertexShader = initShader(GL_VERTEX_SHADER, vertexSource);
    glAttachShader(program->id, vertexShader->id);
    Shader* fragmentShader = initShader(GL_FRAGMENT_SHADER, fragmentSource);
    glAttachShader(program->id, fragmentShader->id);
    Shader* geometryShader = NULL;
    if(geometrySource != NULL){
        geometryShader = initShader(GL_GEOMETRY_SHADER, geometrySource);
        glAttachShader(program->id, geometryShader->id);
    }

    // Link shaders
    glLinkProgram(program->id);

    // Delete shaders
    disposeShader(vertexShader);
    disposeShader(fragmentShader);
    if(geometrySource != NULL){
        disposeShader(geometryShader);
    }

    return program;
}

void disposeShader(Shader* shader){
    glDeleteShader(shader->id);
    free(shader);
}

void disposeProgram(ShaderProgram* program){
    glDeleteProgram(program->id);
    free(program);
}