//
//  Test04.cpp
//  Graphics
//
//  Created by ccf on 2016/12/6.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Test04.h"

#include "Sharp.h"

namespace Test04
{
    class TestPolygon : public IRender
    {
    public:
        virtual ~TestPolygon() {};
        virtual void init() override
        {
            glMatrixMode (GL_PROJECTION);       // Set projection parameters.
            gluOrtho2D (0.0, APP->getWindow()->getWidth(), 0.0, APP->getWindow()->getHeight());
        }
        
        virtual void render() override
        {
            // polygon
            glColor4f(1, 0, 0, 1);
            
            std::vector<Vec2> polygons;
            polygons.push_back(Vec2(10.0f, 30.0f));
            polygons.push_back(Vec2(30.0f, 10.0f));
            polygons.push_back(Vec2(80.0f, 50.0f));
            polygons.push_back(Vec2(50.0f, 100.0f));
            polygons.push_back(Vec2(25.0f, 120.0f));
            BasicDraw::drawPolygon(polygons);
            
            // circle
            glColor4f(0, 0, 1, 1);
            
            std::vector<Vec2> circles;
            int maxCount = 60;
            const float TWO_PI = 3.1415926f * 2.0f;
            float theta = 0.0f;
            float step = TWO_PI / maxCount;
            
            float radius = 50.0f;
            Vec2 center(200.0f, 200.0f);
            for (int i = 0; i < maxCount; ++i)
            {
                theta =  step * i;
                Vec2 circlePoint(center.x + radius * cos(theta),
                                 center.y + radius * sin(theta));
                circles.push_back(circlePoint);
            }
            
            BasicDraw::drawPolygon(circles);
        }
    };
    
    void Test04()
    {
        APP->init("04", 500, 500);
        TestPolygon* pObj = new TestPolygon;
        pObj->init();
        APP->addRenderObj(pObj);
        APP->run();
    }
}


























