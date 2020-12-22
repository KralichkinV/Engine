#include "GraphicsCore.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void GraphicsCore::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GraphicsCore::GraphicsCore(int argc, char* argv[])
{
    m_MainWindow = nullptr;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_MainWindow = glfwCreateWindow(100, 100, "OpenGL for Ravesli.com", 0, 0);
    
    glfwMakeContextCurrent(m_MainWindow);
    glfwSetFramebufferSizeCallback(m_MainWindow, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        throw "tmpmsg";
    }
}

void GraphicsCore::Run()
{
    while (!glfwWindowShouldClose(m_MainWindow))
    {
        // ��������� �����
        processInput(m_MainWindow);

        // ���������� ����������
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: ����� ���������� front- � back- �������. ������������ ������� �����/������ (���� �� ������/�������� ������, ��������� ������ ���� � �.�.)
        glfwSwapBuffers(m_MainWindow);
        glfwPollEvents();
    }

    // glfw: ����������, ������������ ���� ����� ��������������� GLFW-��������
    glfwTerminate();
}

GraphicsCore::~GraphicsCore()
{
    glfwTerminate();
}
