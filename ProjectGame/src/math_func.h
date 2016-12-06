//
//  math_func.h
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef math_func_h
#define math_func_h

#include "PlatformMacros.h"

NS_SP_BEGIN

const float SP_PI = 3.14159265358f;

inline float toRadians(float degrees)
{
    return degrees * SP_PI / 180.0f;
}

inline float toDegrees(float radians)
{
    return radians * 180.0f / SP_PI;
}

// 符号 -1 0 1
inline int sign(float value)
{
    return (value > 0) - (value < 0);
}

inline float clamp(float value, float min, float max)
{
    return (value > min) ? ((value < max) ? value : max) : min;
}

NS_SP_END

#endif /* math_func_h */
























