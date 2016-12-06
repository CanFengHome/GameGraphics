//
//  Application.h
//  SharpStart
//
//  Created by ccf on 2016/10/20.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include "PlatformMacros.h"
#include "SingletonTemplate.h"
#include "Window.h"

NS_SP_BEGIN

#define APP Application::getInstance()

class Application : public SingletonTemplate<Application>
{
public:
    void init(const string& title, int winWidth, int winHeight);
    int run();
private:
    Application();
    virtual ~Application();
    friend class SingletonTemplate<Application>;
    
private:
    void clearAll();
    
private:
    Window* m_pWindow = nullptr;
    std::chrono::steady_clock::time_point m_lastUpdate;
    float m_fDeltaTime = 0.0f;
};

NS_SP_END

#endif /* Application_h */
