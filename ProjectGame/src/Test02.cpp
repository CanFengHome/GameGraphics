//
//  Test02.cpp
//  Graphics
//
//  Created by ccf on 2016/12/6.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Test02.h"

#include "Sharp.h"

namespace Test02
{
    class TestLine : public IRender
    {
    public:
        virtual ~TestLine() {};
        virtual void init() override
        {
            glMatrixMode (GL_PROJECTION);       // Set projection parameters.
            gluOrtho2D (0.0, APP->getWindow()->getWidth(), 0.0, APP->getWindow()->getHeight());
        }
        
        virtual void render() override
        {
            glBegin(GL_LINES);
            glVertex2f(50.0f, 50.0f);
            glVertex2f(200.0f, 200.0f);
            glEnd();

        }
    };
    
    void Test02()
    {
        APP->init("02", 500, 500);
        TestLine* pObj = new TestLine;
        pObj->init();
        APP->addRenderObj(pObj);
        APP->run();
    }
}









