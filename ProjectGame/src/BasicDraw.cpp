//
//  BasicDraw.cpp
//  Graphics
//
//  Created by ccf on 2016/12/6.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "BasicDraw.h"
#include "MacrosAssert.h"

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

void BasicDraw::drawPoint(const std::vector<Vec2>& points)
{
    glBegin(GL_POINTS);
    for (const Vec2& item : points)
    {
        glVertex2f(item.x, item.y);
    }
    glEnd();
}

void BasicDraw::drawPoint(const std::vector<Vec3>& points)
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
    glBegin (GL_POLYGON);
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


















