#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "opengl.h"

VBO* initDynamicVBO(int bufferType, float data[], unsigned int dataSize){
    return initVBO(bufferType, data, dataSize, GL_STATIC_DRAW);
}

VBO* initStaticVBO(int bufferType, float data[], unsigned int dataSize){
    return initVBO(bufferType, data, dataSize, GL_STATIC_DRAW);
}

VBO* initVBO(int bufferType, float data[], unsigned int dataSize, int drawType){
    VBO* vbo = malloc(sizeof(VBO));
    vbo->id = 0;
    vbo->bufferType = bufferType;
    vbo->drawType = drawType;
    glGenBuffers(1, &vbo->id);
    glBindBuffer(bufferType, vbo->id);
    glBufferData(bufferType, dataSize, data, drawType);
    glBindBuffer(bufferType, 0);
    return vbo;
}

void addAttributeVBO(const VBO* vbo, int index, int count){
    glBindBuffer(vbo->bufferType, vbo->id);
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)0);
    glEnableVertexAttribArray(index);
    glBindBuffer(vbo->bufferType, 0);
}

VAO* initVAO(float vertices[], unsigned int verticeSize){
    VAO* vao = malloc(sizeof(VAO));
    vao->id = 0;
    glGenVertexArrays(1, &vao->id);
    glBindVertexArray(vao->id);

    // Vertices
    vao->vbos[0] = initVBO(GL_ARRAY_BUFFER, vertices, verticeSize, GL_STATIC_DRAW);
    addAttributeVBO(vao->vbos[0], 0, 3);

    glBindVertexArray(0);
    return vao;
}

void disposeVAO(const VAO* vao){
    glDeleteBuffers(1, &vao->vbos[0]->id);   // In work

    glDeleteVertexArrays(1, &vao->id);
}