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
    GLFWwindow* window = initWindow(800, 600, "Engine", false);

    if(window == NULL){
        glfwTerminate();
        return ERROR;
    }

    // Create shader program
    glId shaderProgram = initProgram(vertexShaderSource, fragmentShaderSource, NULL);

    if(shaderProgram == 0){
        glfwDestroyWindow(window);
        glfwTerminate();
        return ERROR;
    }

    // VAO && VBO
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO = initVBO(GL_ARRAY_BUFFER, vertices, sizeof(vertices), GL_STATIC_DRAW);
    // Positions
    addAttributeVBO(VBO, GL_ARRAY_BUFFER, 0, 3);

    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window))
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glClearColor(0.5f, 0.2f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}