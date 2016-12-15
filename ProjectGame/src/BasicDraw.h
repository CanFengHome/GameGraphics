//
//  BasicDraw.h
//  Graphics
//
//  Created by ccf on 2016/12/6.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef BasicDraw_h
#define BasicDraw_h

#include "PlatformMacros.h"
#include "ExternHeader.h"
#include "MathHeader.h"

class BasicDraw
{
public:
    static void drawPoint(const Vec2& point);
    static void drawPoints(const std::vector<Vec2>& points);
    static void drawPoint(const Vec3& point);
    static void drawPoints(const std::vector<Vec3>& points);
    
    static void drawPolygon(const std::vector<Vec2>& points);
    static void drawPolygon(const std::vector<Vec3>& points);
    
    static void drawRect(const Vec2& leftBottomPt, const Vec2& rightTopPt);
    
    static void drawImage(int imgWidth, int imgHeight, const Vec2& drawLeftTopPt, const unsigned char* const pImageData);
    static void drawImageGL(int imgWidth, int imgHeight, const Vec2& drawLeftTopPt, const unsigned char* const pImageData);
    
    static void drawLine(float x1, float y1, float x2, float y2);
};

#endif /* BasicDraw_h */















