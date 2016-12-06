//
//  IRenderObj.h
//  OpenGLStudy
//
//  Created by ccf on 16/10/10.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef IRenderObj_h
#define IRenderObj_h

#include "PlatformMacros.h"

NS_SP_BEGIN

struct IRender
{
    virtual ~IRender() {};
    virtual void init() = 0;
    virtual void render() = 0;
};

NS_SP_END

#endif /* IRenderObj_h */
