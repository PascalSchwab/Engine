typedef const unsigned int glId;

typedef struct{
    unsigned int id;
    unsigned int bufferType;
    unsigned int drawType;
}VBO;

typedef struct{
    unsigned int id;
    VBO* vbos[3];
}VAO;

VBO* initDynamicVBO(int bufferType, float data[], unsigned int dataSize);

VBO* initStaticVBO(int bufferTpye, float data[], unsigned int dataSize);

VBO* initVBO(int bufferType, float data[], unsigned int dataSize, int drawType);

void addAttributeVBO(const VBO* vbo, int index, int count);

VAO* initVAO(float vertices[], unsigned int verticeSize);

void disposeVAO(const VAO* vao);