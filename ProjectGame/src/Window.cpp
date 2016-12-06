//
//  Window.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/7.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Window.h"

NS_SP_BEGIN

void window_resize(GLFWwindow* pWindow, int width, int height)
{
    Window* pWin = (Window*)glfwGetWindowUserPointer(pWindow);
    pWin->m_iWidth = width;
    pWin->m_iHeight = height;
    
    glViewport(0, 0, width, height);
}

void window_keyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(pWindow, GL_TRUE);

    Window* pWin = (Window*)glfwGetWindowUserPointer(pWindow);
    pWin->m_Keys[key] = action != GLFW_RELEASE;
}

void window_mouseButtonCallback(GLFWwindow* pWindow, int button, int action, int mods)
{
    Window* pWin = (Window*)glfwGetWindowUserPointer(pWindow);
    pWin->m_MouseButtons[button] = action != GLFW_RELEASE;
}

void window_mouseCursorPositionCallback(GLFWwindow* pWindow, double xpos, double ypos)
{
    Window* pWin = (Window*)glfwGetWindowUserPointer(pWindow);
    pWin->m_cursorPos.x = (float)xpos;
    pWin->m_cursorPos.y = (float)ypos;
}

void window_scrollCallback(GLFWwindow* pWindow, double xoffset, double yoffset)
{
    
}

Window::Window(const string& winTitle, int winWidth, int winHeight)
{
    m_strTitle = winTitle;
    m_iWidth = winWidth;
    m_iHeight = winHeight;
    m_pWindow = nullptr;
    m_ClearColor = {0.2f, 0.3f, 0.3f, 1.0f};
    
    if (!init())
        glfwTerminate();
    
    for (int i = 0; i < MAX_KEYS; ++i)
    {
        m_Keys[i] = false;
    }
    
    for (int i = 0; i < MAX_BUTTONS; ++i)
    {
        m_MouseButtons[i] = false;
    }
}

Window::~Window()
{
    glfwTerminate();
}

bool Window::init()
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        return false;
    }
    
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    m_pWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_strTitle.c_str(), nullptr, nullptr);
    if (!m_pWindow)
    {
        glfwTerminate();
        std::cout << "Failed to create GLFW window!" << std::endl;
        return false;
    }
    glfwMakeContextCurrent(m_pWindow);
    
    glfwSetKeyCallback(m_pWindow, window_keyCallback);
    glfwSetWindowUserPointer(m_pWindow, this);
    glfwSetWindowSizeCallback(m_pWindow, window_resize);
    glfwSetMouseButtonCallback(m_pWindow, window_mouseButtonCallback);
    glfwSetCursorPosCallback(m_pWindow, window_mouseCursorPositionCallback);
    glfwSetScrollCallback(m_pWindow, window_scrollCallback);

    initGlew();

    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
    
    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(m_pWindow, &width, &height);
    glViewport(0, 0, width, height);
    
    // Enable point size by default.
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL); // GLFW_CURSOR_HIDDEN
    
    // Setup OpenGL options
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    
    return true;
}

void Window::initGlew()
{
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        std::cout << "Could not initialize GLEW" << std::endl;
        return;
    }
}

bool Window::isKeyPressed(unsigned int keycode) const
{
    if (keycode >= MAX_KEYS)
    {
        return false;
    }
    
    return m_Keys[keycode];
}

bool Window::isMouseButtonPressed(unsigned int button) const
{
    if (button >= MAX_BUTTONS)
    {
        return false;
    }
    
    return m_MouseButtons[button];
}

void Window::clear() const
{
    glfwPollEvents();
    glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::closed() const
{
    return glfwWindowShouldClose(m_pWindow) == 1;
}

void Window::update() const
{
    glfwSwapBuffers(m_pWindow);
}


NS_SP_END















