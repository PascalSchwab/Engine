typedef const unsigned int glId;

typedef struct{
    unsigned int id;
    unsigned int bufferType;
}VBO;

unsigned int initDynamicVBO(int bufferType, float data[], unsigned int dataSize);

unsigned int initStaticVBO(int bufferTpye, float data[], unsigned int dataSize);

unsigned int initVBO(int bufferType, float data[], unsigned int dataSize, int drawType);

void addAttributeVBO(unsigned int vbo, int bufferType, int index, int count);