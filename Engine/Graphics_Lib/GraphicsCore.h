#pragma once
#include "glad.h"
#include "glfw3.h"

class GraphicsCore
{
private:
    //obj
    GLFWwindow* m_MainWindow;

    //func
    GraphicsCore() = delete;
    //void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);
public:
    GraphicsCore(int argc, char* argv[]);
    void Run();
    ~GraphicsCore();
};

