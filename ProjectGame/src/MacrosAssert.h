//
//  MacrosAssert.h
//  Hello
//
//  Created by ccf on 16/5/31.
//
//

#ifndef MacrosAssert_h
#define MacrosAssert_h

#include <cassert>

#define CC_RETURN_IF(condition)                 if(condition) return
#define CC_RETURN_VALUE_IF(condition,value)     if(condition) return value
#define CC_RETURN_IF_ASSERT_FAIL(cond)          assert(cond);  if(!(cond)) return
#define CC_RETURN_VALUE_IF_ASSERT_FAIL(cond,value)          assert(cond);  if(!(cond)) return value

#endif /* MacrosAssert_h */
