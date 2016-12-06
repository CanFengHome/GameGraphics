//
//  PlatformMacros.h
//  SharpEngine
//
//  Created by ccf on 16/9/7.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef PlatformMacros_h
#define PlatformMacros_h

#include <cassert>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <random>

#define NS_SP_BEGIN          
#define NS_SP_END
#define USING_NS_SP
#define NS_SP

#ifdef DEBUG
#define SPLOG(format, ...) printf(format, ##__VA_ARGS__)
#else
#define SPLOG(format, ...)
#endif

#define SPASSERT(cond) assert(cond)

#define CHECK_GL_ERROR_DEBUG() \
do { \
GLenum __error = glGetError(); \
if(__error) { \
SPLOG("OpenGL error 0x%04X in %s %s %d\n", __error, __FILE__, __FUNCTION__, __LINE__); \
} \
} while (false)

#define CC_SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define CC_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define CC_SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)


#define CC_DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName &) = delete; \
TypeName &operator =(const TypeName &) = delete;

#ifndef MIN
#define MIN(x,y) (((x) > (y)) ? (y) : (x))
#endif  // MIN

#ifndef MAX
#define MAX(x,y) (((x) < (y)) ? (y) : (x))
#endif  // MAX

#endif /* PlatformMacros_h */




















