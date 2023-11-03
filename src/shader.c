#include "shader.h"

Shader* initShader(int shaderType, const char* source){
    Shader* shader = malloc(sizeof(Shader));
    shader->shaderType = shaderType;
    shader->id = glCreateShader(shaderType);
    glShaderSource(shader->id, 1, &source, NULL);
    glCompileShader(shader->id);
    return shader;
}

ShaderProgram* initProgram(char* vertexShaderPath, char* fragmentShaderPath, char* geometryShaderPath){
    ShaderProgram* program = malloc(sizeof(ShaderProgram));
    program->vertexShaderFile = NULL;
    program->fragmentShaderFile = NULL;
    program->geometryShaderFile = NULL;

    // Vertex and Fragment shader are required
    if(vertexShaderPath == NULL){
        perror("Vertex Shader Path is not defined");
        return NULL;
    }
    if(fragmentShaderPath == NULL){
        perror("Fragment Shader Path is not defined");
        return NULL;
    }
    
    program->id = glCreateProgram();

    // Read Files
    program->vertexShaderFile = readFile(vertexShaderPath);
    if(program->vertexShaderFile == NULL){
        perror("Vertex Shader Path is wrong");
        return NULL;
    }
    program->fragmentShaderFile = readFile(fragmentShaderPath);
    if(program->fragmentShaderFile == NULL){
        perror("Fragment Shader Path is wrong");
        return NULL;
    }
    if(geometryShaderPath != NULL){
        program->geometryShaderFile = readFile(geometryShaderPath);
        if(program->geometryShaderFile == NULL){
            perror("Geometry Shader Path is wrong");
            return NULL;
        }
    }

    // Init shaders
    Shader* vertexShader = initShader(GL_VERTEX_SHADER, program->vertexShaderFile->text);
    glAttachShader(program->id, vertexShader->id);
    Shader* fragmentShader = initShader(GL_FRAGMENT_SHADER, program->fragmentShaderFile->text);
    glAttachShader(program->id, fragmentShader->id);
    Shader* geometryShader = NULL;
    if(geometryShaderPath != NULL){
        geometryShader = initShader(GL_GEOMETRY_SHADER, program->geometryShaderFile->text);
        glAttachShader(program->id, geometryShader->id);
    }

    // Link shaders
    glLinkProgram(program->id);

    // Delete shaders
    disposeShader(vertexShader);
    disposeShader(fragmentShader);
    if(geometryShaderPath != NULL){
        disposeShader(geometryShader);
    }

    return program;
}

void disposeShader(Shader* shader){
    glDeleteShader(shader->id);
    free(shader);
}

void disposeProgram(ShaderProgram* program){
    free(program->vertexShaderFile->text);
    free(program->vertexShaderFile);
    free(program->fragmentShaderFile->text);
    free(program->fragmentShaderFile);
    if(program->geometryShaderFile != NULL){
        free(program->vertexShaderFile->text);
        free(program->vertexShaderFile);
    }
    glDeleteProgram(program->id);
    free(program);
}