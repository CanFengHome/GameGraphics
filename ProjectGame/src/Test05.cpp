//
//  Test05.cpp
//  Graphics
//
//  Created by ccf on 2016/12/7.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Test05.h"

#include "Sharp.h"

namespace Test05
{
    class TestImage : public IRender
    {
    public:
        virtual ~TestImage()
        {
            if (m_pImageData)
            {
                SOIL_free_image_data(m_pImageData);
            }
        };
        
        virtual void init() override
        {
            glMatrixMode (GL_PROJECTION);       // Set projection parameters.
            gluOrtho2D (0.0, APP->getWindow()->getWidth(), 0.0, APP->getWindow()->getHeight());
            
            m_pImageData = SOIL_load_image("res/texture/awesomeface.png", &m_iImgWidth, &m_iImgHeight, 0, SOIL_LOAD_RGBA);
        }
        
        virtual void render() override
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glRectf(200.0f, 200.0f, 400.0f, 400.0f);
            
            BasicDraw::drawImageGL(m_iImgWidth, m_iImgHeight, Vec2(100.0f, 200.0f), m_pImageData);
        }
    private:
        unsigned char* m_pImageData = nullptr;
        int m_iImgWidth, m_iImgHeight;
    };
    
    void Test05()
    {
        APP->init("05", 500, 500);
        TestImage* pObj = new TestImage;
        pObj->init();
        APP->addRenderObj(pObj);
        APP->run();
    }
}

































