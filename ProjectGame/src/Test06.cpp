//
//  Test06.cpp
//  Graphics
//
//  Created by ccf on 2016/12/7.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Test06.h"

#include "Sharp.h"

namespace Test06
{
    unsigned char happy_bitmap[64] = {0,0,0,0,0,0,0,0,
                                    0,0,1,1,1,1,0,0,
                                    0,1,0,1,1,0,1,0,
                                    0,1,1,1,1,1,1,0,
                                    0,1,0,1,1,0,1,0,
                                    0,1,1,0,0,1,1,0,
                                    0,0,1,1,1,1,0,0,
                                    0,0,0,0,0,0,0,0};
        
    unsigned char sad_bitmap[64] = {0,0,0,0,0,0,0,0,
                                    0,0,1,1,1,1,0,0,
                                    0,1,0,1,1,0,1,0,
                                    0,1,1,1,1,1,1,0,
                                    0,1,1,0,0,1,1,0,
                                    0,1,0,1,1,0,1,0,
                                    0,0,1,1,1,1,0,0,
                                    0,0,0,0,0,0,0,0};
    
    class TestImageCustom : public IRender
    {
    public:
        struct HappyFaceType
        {
            int x,y;
            int xv, yv;
        };
        
        virtual ~TestImageCustom()
        {
        };
        
        virtual void init() override
        {
            glMatrixMode (GL_PROJECTION);       // Set projection parameters.
            gluOrtho2D (0.0, APP->getWindow()->getWidth(), 0.0, APP->getWindow()->getHeight());
            
            APP->getWindow()->setClearColor(0, 0, 0, 1);
            
            m_iWinWidth = APP->getWindow()->getWidth();
            m_iWinHeight = APP->getWindow()->getHeight();
            for (int face = 0; face < 100; ++face)
            {
                HappyFaceType faceItem;
                faceItem.x = RandomHelper::random_int(0, m_iWinWidth);
                faceItem.y = RandomHelper::random_int(0, m_iWinHeight);
                faceItem.xv = rand_minus1_1() * 2;
                faceItem.yv = rand_minus1_1() * 2;
                
                m_arrFaces.push_back(faceItem);
            }
        }
        
        virtual void render() override
        {
            for (const HappyFaceType& item : m_arrFaces)
            {
                BasicDraw::drawImage(8, 8, Vec2(item.x, item.y), happy_bitmap);
            }
            
            for (HappyFaceType& item : m_arrFaces)
            {
                item.x += item.xv;
                item.y += item.yv;
                
                // check for off screen, if so wrap
                if (item.x > m_iWinWidth)
                    item.x = -8;
                else
                    if (item.x < -8)
                        item.x = m_iWinWidth;
                
                if (item.y > m_iWinHeight)
                    item.y = -8;
                else
                    if (item.y < -8)
                        item.y = m_iWinHeight;
            }
        }
    private:
        std::vector<HappyFaceType> m_arrFaces;
        
        int m_iWinWidth = 0;
        int m_iWinHeight = 0;
    };
    
    void Test06()
    {
        APP->init("06", 500, 500);
        TestImageCustom* pObj = new TestImageCustom;
        pObj->init();
        APP->addRenderObj(pObj);
        APP->run();
    }
}

































