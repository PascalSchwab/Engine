typedef struct{
    unsigned int id;
    unsigned int bufferType;
    unsigned int drawType;
}GLBuffer;

typedef struct{
    unsigned int id;
}VAO;

GLBuffer* initIntGLBuffer(int bufferType, unsigned int data[], unsigned int dataSize, int drawType);

GLBuffer* initFloatGLBuffer(int bufferType, float data[], unsigned int dataSize, int drawType);

void addAttributeGLBuffer(const GLBuffer* glBuffer, int index, int count);

VAO* initVAO();

void disposeGLBuffer(GLBuffer* glBuffer);

void disposeVAO(VAO* vao);