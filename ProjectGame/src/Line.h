//
//  Line.h
//  Graphics
//
//  Created by ccf on 2016/12/8.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Line_h
#define Line_h

#include "BasicDraw.h"
#include "IRenderObj.h"

class Line : public IRender
{
public:
    Line()
    :x1(0.0f),y1(0.0f),x2(0.0f),y2(0.0f)
    {
        
    }
    
    Line(float ptX1, float ptY1, float ptX2, float ptY2)
    :x1(ptX1), y1(ptY1), x2(ptX2), y2(ptY2)
    {
        
    }
    
    virtual void init() override;
    virtual void render() override;
    
    void applyCupLineWithWindowRect();
    // rectX1-minX rectY1-minY
    void applyCupLineWithRect(float rectX1, float rectY1, float rectX2, float rectY2);
public:
    float x1;
    float y1;
    float x2;
    float y2;
    
private:
    bool m_bCanDraw = true;
};

#endif /* Line_h */
