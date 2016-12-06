//
//  Color.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/27.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Color.h"

NS_SP_BEGIN

/**
 * Color4B
 */

Color4B::Color4B()
: r(0)
, g(0)
, b(0)
, a(0)
{}

Color4B::Color4B(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
: r(_r)
, g(_g)
, b(_b)
, a(_a)
{}

Color4B::Color4B(const Color4F& color)
: r(color.r * 255)
, g(color.g * 255)
, b(color.b * 255)
, a(color.a * 255)
{}

const Color4B Color4B::WHITE  (255, 255, 255, 255);
const Color4B Color4B::YELLOW (255, 255,   0, 255);
const Color4B Color4B::GREEN  (  0, 255,   0, 255);
const Color4B Color4B::BLUE   (  0,   0, 255, 255);
const Color4B Color4B::RED    (255,   0,   0, 255);
const Color4B Color4B::MAGENTA(255,   0, 255, 255);
const Color4B Color4B::BLACK  (  0,   0,   0, 255);
const Color4B Color4B::ORANGE (255, 127,   0, 255);
const Color4B Color4B::GRAY   (166, 166, 166, 255);



/**
 * Color4F
 */
Color4F::Color4F()
: r(0.0f)
, g(0.0f)
, b(0.0f)
, a(0.0f)
{}

Color4F::Color4F(float _r, float _g, float _b, float _a)
: r(_r)
, g(_g)
, b(_b)
, a(_a)
{}


Color4F::Color4F(const Color4B& color)
: r(color.r / 255.0f)
, g(color.g / 255.0f)
, b(color.b / 255.0f)
, a(color.a / 255.0f)
{}


const Color4F Color4F::WHITE  (    1,     1,     1, 1);
const Color4F Color4F::YELLOW (    1,     1,     0, 1);
const Color4F Color4F::GREEN  (    0,     1,     0, 1);
const Color4F Color4F::BLUE   (    0,     0,     1, 1);
const Color4F Color4F::RED    (    1,     0,     0, 1);
const Color4F Color4F::MAGENTA(    1,     0,     1, 1);
const Color4F Color4F::BLACK  (    0,     0,     0, 1);
const Color4F Color4F::ORANGE (    1,  0.5f,     0, 1);
const Color4F Color4F::GRAY   (0.65f, 0.65f, 0.65f, 1);



NS_SP_END






















