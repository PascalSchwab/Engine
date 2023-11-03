#include "main.h"

float vertices[] = {
     0.5f,  0.5f, 0.0f, 
     0.5f, -0.5f, 0.0f, 
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
};

unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
}; 

Window* window;

ShaderProgram* program;

Mesh* mesh;

int main(){
    glfwInit();

    int status = startEngine();

    glfwTerminate();

    return status;
}

static int startEngine(){
    // Create Window
    window = initWindow(800, 600, "Engine", false);

    if(window == NULL){
        return ERROR;
    }

    // Create shader program
    program = initProgram("../assets/main.vert", "../assets/main.frag", NULL);

    if(program == NULL){
        disposeWindow(window);
        return ERROR;
    }

    // VAO
    mesh = initMesh(vertices, sizeof(vertices), indices, sizeof(indices));

    // Set color
    glClearColor(0.5f, 0.2f, 0.7f, 1.0f);

    // While loop
    loop();

    dispose();
    return SUCCESS;
}

static void loop(){
    while(!glfwWindowShouldClose(window->window)){
        update();

        render();

        glfwSwapBuffers(window->window);
        glfwPollEvents(); 
    }
}

static void update(){
    if(glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);
}

static void render(){
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program->id);
    glBindVertexArray(mesh->vao->id);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

static void dispose(){
    disposeProgram(program);
    disposeMesh(mesh);
    disposeWindow(window);
}