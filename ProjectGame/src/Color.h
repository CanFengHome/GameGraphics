//
//  Color.h
//  SharpEngine
//
//  Created by ccf on 16/9/27.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Color_h
#define Color_h

#include "PlatformMacros.h"
#include "ExternHeader.h"

NS_SP_BEGIN

struct Color4F;
struct Color4B
{
    Color4B();
    Color4B(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a);
    explicit Color4B(const Color4F& color);
    
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
    
    static const Color4B WHITE;
    static const Color4B YELLOW;
    static const Color4B BLUE;
    static const Color4B GREEN;
    static const Color4B RED;
    static const Color4B MAGENTA;
    static const Color4B BLACK;
    static const Color4B ORANGE;
    static const Color4B GRAY;
};

struct Color4F
{
    Color4F();
    Color4F(float _r, float _g, float _b, float _a);
    explicit Color4F(const Color4B& color);

    inline void setColor(float _r, float _g, float _b, float _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
    
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
    
    static const Color4F WHITE;
    static const Color4F YELLOW;
    static const Color4F BLUE;
    static const Color4F GREEN;
    static const Color4F RED;
    static const Color4F MAGENTA;
    static const Color4F BLACK;
    static const Color4F ORANGE;
    static const Color4F GRAY;
};

NS_SP_END

#endif /* Color_h */











