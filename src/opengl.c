#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>

#include "opengl.h"

unsigned int initDynamicVBO(int bufferType, float data[], unsigned int dataSize){
    return initVBO(bufferType, data, dataSize, GL_STATIC_DRAW);
}

unsigned int initStaticVBO(int bufferType, float data[], unsigned int dataSize){
    return initVBO(bufferType, data, dataSize, GL_STATIC_DRAW);
}

unsigned int initVBO(int bufferType, float data[], unsigned int dataSize, int drawType){
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(bufferType, buffer);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, drawType);
    glBindBuffer(bufferType, 0);
    return buffer;
}

void addAttributeVBO(unsigned int vbo, int bufferType, int index, int count){
    glBindBuffer(bufferType, vbo);
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(bufferType, 0);
}