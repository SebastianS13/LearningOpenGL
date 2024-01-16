#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    std::cout << "Initiated GLFW" << std::endl;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1250, 1000, "Learning OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    std::cout << "Created Window" << std::endl;

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout << "Set OpenGL window context" << std::endl;

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Glew is not in fact OK" << std::endl;
    }

    std::cout << "Initiated Glew" << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}