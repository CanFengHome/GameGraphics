//
//  Test07.cpp
//  Graphics
//
//  Created by ccf on 2016/12/15.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Test07.h"

#include "Sharp.h"

namespace Test07
{
    class TestCupLine : public IRender
    {
    public:
        virtual ~TestCupLine() {};
        virtual void init() override
        {
            glMatrixMode (GL_PROJECTION);       // Set projection parameters.
            gluOrtho2D (0.0, APP->getWindow()->getWidth(), 0.0, APP->getWindow()->getHeight());
            
            
            m_rectPt1 = Vec2(100.0f, 100.0f);
            m_rectPt2 = Vec2(400.0f, 400.0f);
            
            m_line.x1 = 10.0f;
            m_line.y1 = 150.0f;
            
            m_line.x2 = 300.0f;
            m_line.y2 = 450.0f;
            
            m_line.applyCupLineWithRect(m_rectPt1.x, m_rectPt1.y, m_rectPt2.x, m_rectPt2.y);
        }
        
        virtual void render() override
        {
            glLineWidth(5.0f);
            glColor3f(1.0f, 0.0f, 0.0f);
            BasicDraw::drawLine(m_line.x1, m_line.y1, m_line.x2, m_line.y2);
            
            glColor3f(0.0f, 0.0f, 1.0f);
            BasicDraw::drawRect(m_rectPt1, m_rectPt2);
        }
        
    private:
        Line m_line;
        Vec2 m_rectPt1;
        Vec2 m_rectPt2;
    };
    
    void Test07()
    {
        APP->init("07", 500, 500);
        TestCupLine* pObj = new TestCupLine;
        pObj->init();
        APP->addRenderObj(pObj);
        APP->run();
    }
}





































