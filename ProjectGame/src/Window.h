//
//  Window.h
//  SharpEngine
//
//  Created by ccf on 16/9/7.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Window_h
#define Window_h

#include "PlatformMacros.h"
#include "ExternHeader.h"
#include "Color.h"
#include "Vec2.h"

NS_SP_BEGIN

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window
{
public:
    Window(const string& winTitle, int winWidth, int winHeight);
    ~Window();
    
    void clear() const;
    void update() const;
    bool closed() const;
    
    bool isKeyPressed(unsigned int keycode) const;
    bool isMouseButtonPressed(unsigned int button) const;
    
    inline Vec2 getCursorPos() const { return m_cursorPos; }
    inline float getWidth() const { return m_iWidth; }
    inline float getHeight() const {return m_iHeight; }
    
    inline void setClearColor(float _r, float _g, float _b, float _a)
    {
        m_clearColor.setColor(_r, _g, _b, _a);
    }
    
    inline void setFrontColor(float _r, float _g, float _b, float _a)
    {
        m_frontColor.setColor(_r, _g, _b, _a);
    }
    
    inline float getAspactRatio() const
    {
        return (float)m_iWidth / (float)m_iHeight;
    }
private:
    bool init();
    void initGlew();
private:
    string m_strTitle;
    int m_iWidth;
    int m_iHeight;
    
    GLFWwindow* m_pWindow;
    bool m_Keys[MAX_KEYS];
    bool m_MouseButtons[MAX_BUTTONS];
    
    Vec2 m_cursorPos;
    Color4F m_clearColor;
    Color4F m_frontColor;
    
private:
    friend void window_resize(GLFWwindow* pWindow, int width, int height);
    friend void window_keyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods);
    friend void window_mouseButtonCallback(GLFWwindow* pWindow, int button, int action, int mods);
    friend void window_mouseCursorPositionCallback(GLFWwindow* pWindow, double xpos, double ypos);
    friend void window_scrollCallback(GLFWwindow* pWindow, double xoffset, double yoffset);
};


NS_SP_END

#endif /* Window_h */
