#ifndef __MESH__
#define __MESH__

#include "main.h"

typedef struct 
{
    VAO* vao;
    GLBuffer* glBuffers[3];
} Mesh;

Mesh* initMesh(float vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);

void disposeMesh(Mesh* mesh);

#endif