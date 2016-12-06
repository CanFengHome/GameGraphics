//
//  Test03.cpp
//  Graphics
//
//  Created by ccf on 2016/12/6.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Test03.h"

#include "Sharp.h"

namespace Test03
{
    class TestFont : public IRender
    {
    public:
        virtual ~TestFont() {};
        virtual void init() override
        {
            glMatrixMode (GL_PROJECTION);       // Set projection parameters.
            gluOrtho2D (0.0, APP->getWindow()->getWidth(), 0.0, APP->getWindow()->getHeight());
        }
        
        virtual void render() override
        {
//            glPointSize(2);
            float winWidth = APP->getWindow()->getWidth();
            float winHeight = APP->getWindow()->getHeight();
            
            for (int index=0; index < 1000; index++)
            {
                // get random position
                float x = RandomHelper::random_real(0.0f, winWidth);
                float y = RandomHelper::random_real(0.0f, winHeight);
                
                Color4F color(rand_0_1(), rand_0_1(), rand_0_1(), 1.0);
                glColor4f(color.r, color.g, color.b, color.a);
                
                BasicDraw::drawPoint(Vec2(x, y));
            }
        }
    };
    
    void Test03()
    {
        APP->init("03", 500, 500);
        TestFont* pObj = new TestFont;
        pObj->init();
        APP->addRenderObj(pObj);
        APP->run();
    }
}
















