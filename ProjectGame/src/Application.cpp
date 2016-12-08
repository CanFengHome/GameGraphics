//
//  Application.cpp
//  SharpStart
//
//  Created by ccf on 2016/10/20.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Application.h"

NS_SP_BEGIN

Application::Application()
{
    
}

Application::~Application()
{
    clearAll();
}

void Application::init(const string& title, int winWidth, int winHeight)
{
    clearAll();
    
    m_pWindow = new Window(title, winWidth, winHeight);
}

int Application::run()
{
    const float INTERVAL = 1.0f/60.0f*1000000.0f;
    // loop
    while (!m_pWindow->closed())
    {
        std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now();
        float interval = std::chrono::duration_cast<std::chrono::microseconds>(nowTime - m_lastUpdate).count();
        
        if (interval >= INTERVAL)
        {
            m_fDeltaTime = interval / 1000000.0f;
#if DEBUG
            // If we are debugging our code, prevent big delta time
            if (m_fDeltaTime > 0.2f)
            {
                m_fDeltaTime = 1 / 60.0f;
            }
#endif
            m_fDeltaTime = MAX(0.0f, m_fDeltaTime);
            m_lastUpdate = nowTime;
            
//            std::cout << "render... interval " << m_fDeltaTime << std::endl;
            
            m_pWindow->clear();
            
            for (IRender* pRenderObj : m_arrRenderObjs)
            {
                pRenderObj->render();
            }
            
            m_pWindow->update();
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::microseconds((long long)(INTERVAL-interval)));
        }
    }

    // release
    
    return 0;
}

void Application::clearAll()
{
    for (IRender* pRenderObj : m_arrRenderObjs)
    {
        CC_SAFE_DELETE(pRenderObj);
    }
    m_arrRenderObjs.clear();
    
    CC_SAFE_DELETE(m_pWindow);
}

void Application::addRenderObj(IRender* pRenderObj)
{
    m_arrRenderObjs.push_back(pRenderObj);
}

Window* Application::getWindow()
{
    return m_pWindow;
}












NS_SP_END







