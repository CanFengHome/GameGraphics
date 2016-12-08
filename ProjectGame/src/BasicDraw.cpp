//
//  BasicDraw.cpp
//  Graphics
//
//  Created by ccf on 2016/12/6.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "BasicDraw.h"
#include "MacrosAssert.h"
#include "Application.h"

void BasicDraw::drawPoint(const Vec2& point)
{
    glBegin(GL_POINTS);
    glVertex2f(point.x, point.y);
    glEnd();
}

void BasicDraw::drawPoint(const Vec3& point)
{
    glBegin(GL_POINTS);
    glVertex3f(point.x, point.y, point.z);
    glEnd();
}

void BasicDraw::drawPoints(const std::vector<Vec2>& points)
{
    glBegin(GL_POINTS);
    for (const Vec2& item : points)
    {
        glVertex2f(item.x, item.y);
    }
    glEnd();
}

void BasicDraw::drawPoints(const std::vector<Vec3>& points)
{
    glBegin(GL_POINTS);
    for (const Vec3& item : points)
    {
        glVertex3f(item.x, item.y, item.z);
    }
    glEnd();
}

void BasicDraw::drawPolygon(const std::vector<Vec2>& points)
{
    CC_RETURN_IF_ASSERT_FAIL(points.size() >= 3);
    glBegin (GL_POLYGON); // gl_line_loop
    for (const Vec2& item : points)
    {
        glVertex2f(item.x, item.y);
    }
    glEnd();
}

void BasicDraw::drawPolygon(const std::vector<Vec3>& points)
{
    CC_RETURN_IF_ASSERT_FAIL(points.size() >= 3);
    
    glBegin (GL_POLYGON);
    for (const Vec3& item : points)
    {
        glVertex3f(item.x, item.y, item.z);
    }
    glEnd();
}

void BasicDraw::drawRect(const Vec2& leftBottomPt, const Vec2& rightTopPt)
{
    glRectf(leftBottomPt.x, leftBottomPt.y, rightTopPt.x, rightTopPt.y);
}

void BasicDraw::drawImageGL(int imgWidth, int imgHeight, const Vec2& drawLeftTopPt, const unsigned char* const pImageData)
{
    // 注意：如果是加载透明度的图片，需要提前开启
    // glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    CC_RETURN_IF_ASSERT_FAIL(pImageData != nullptr);
    
    // image
    glRasterPos2f(drawLeftTopPt.x, drawLeftTopPt.y);
    glPixelZoom(1.0f, -1.0f);
    
    glDrawPixels(imgWidth, imgHeight, GL_RGBA, GL_UNSIGNED_BYTE, pImageData);
}

void BasicDraw::drawImage(int imgWidth, int imgHeight, const Vec2& drawLeftTopPt, const unsigned char* const pImageData)
{
    int winWidth = APP->getWindow()->getWidth();
    int winHeight = APP->getWindow()->getHeight();
    int x = drawLeftTopPt.x;
    int y = drawLeftTopPt.y;
    
    if (x >= winWidth ||
        y >= winHeight ||
        (x + imgWidth) <= 0 ||
        (y + imgHeight) <= 0)
    {
        return;
    }
    
    int x1 = x;
    int y1 = y;
    int x2 = x1 + imgWidth - 1;
    int y2 = y1 + imgHeight -1;
    
    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    
    if (x2 >= winWidth)
        x2 = winWidth - 1;
    
    if (y2 >= winHeight)
        y2 = winHeight - 1;
    
    unsigned char pixel;
    for (int index_y = y1; index_y <= y2; index_y++)
    {
        // inner loop, where the action takes place
        for (int index_x = x1; index_x < x2; index_x++)
        {
            int imgIndex = (index_x - x1) + (index_y - y1) * imgWidth;
            pixel = pImageData[imgIndex];
            if (pixel != 0)
            {
                glColor4f(pixel, pixel, pixel, 1);
                
                glBegin(GL_POINTS);
                glVertex2f(index_x, index_y);
                glEnd();
            }
        }
    }
}


//glLineStipple(2, 0x0F0F);//设置虚线的样式
//glLineWidth(10.0f);//指定线宽

//从三维的角度来看，一个多边形具有两个面。每一个面都可以设置不同的绘制方式：填充、只绘制边缘轮廓线、只绘制顶点，其中“填充”是默认的方式。可以为两个面分别设置不同的方式。
//glPolygonMode(GL_FRONT, GL_FILL);           // 设置正面为填充方式
//glPolygonMode(GL_BACK, GL_LINE);            // 设置反面为边缘绘制方式
//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); // 设置两面均为顶点绘制方式

//glFrontFace(GL_CCW);  // 设置CCW方向为“正面”，CCW即CounterClockWise，逆时针
//glFrontFace(GL_CW);   // 设置CW方向为“正面”，CW即ClockWise，顺时针

//glEnable(GL_CULL_FACE);来启动剔除功能 使用glDisable(GL_CULL_FACE)可以关闭之
//然后，使用glCullFace来进行剔除。glCullFace的参数可以是GL_FRONT，GL_BACK或者GL_FRONT_AND_BACK，分别表示剔除正面、剔除反面、剔除正反两面的多边形。

//使用glEnable(GL_POLYGON_STIPPLE);来启动镂空模式（使用glDisable(GL_POLYGON_STIPPLE)可以关闭之）
//使用glPolygonStipple来设置镂空的样式。 void glPolygonStipple(const GLubyte *mask);




