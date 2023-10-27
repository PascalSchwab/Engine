#include "main.h"

const char* vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main(){
    glfwInit();
    
    // Create Window
    Window* window = initWindow(800, 600, "Engine", false);

    if(window == NULL){
        glfwTerminate();
        return ERROR;
    }

    // Create shader program
    ShaderProgram* shaderProgram = initProgram(vertexShaderSource, fragmentShaderSource, NULL);

    if(shaderProgram == NULL){
        disposeWindow(window);
        glfwTerminate();
        return ERROR;
    }

    // VAO
    VAO* vao = initVAO(vertices, sizeof(vertices));

    while(!glfwWindowShouldClose(window->window))
    {
        if(glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(0.5f, 0.2f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram->id);
        glBindVertexArray(vao->id);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    disposeProgram(shaderProgram);
    disposeVAO(vao);
    disposeWindow(window);
    glfwTerminate();
    return 0;
}