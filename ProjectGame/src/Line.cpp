//
//  Line.cpp
//  Graphics
//
//  Created by ccf on 2016/12/8.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include "Line.h"

#include "BasicDraw.h"
#include "Application.h"

void Line::init()
{
    
}

void Line::render()
{
    BasicDraw::drawLine(x1, y1, x2, y2);
}

void Line::applyCupLineWithWindowRect()
{
    int winWidth = APP->getWindow()->getWidth();
    int winHeight = APP->getWindow()->getHeight();
    
    applyCupLineWithRect(0.0f, 0.0f, winWidth, winHeight);
}

// 第一位：若端点位于窗口之左侧，即x<wxl，则C1=1，否则C1=0
// 第二位：若端点位于窗口之右侧，即x>wxr，则C2=1，否则C2=0
// 第三位：若端点位于窗口之下侧，即y<wyb，则C3=1，否则C3=0
// 第四位：若端点位于窗口之上侧，即y>wyt，则C4=1，否则C4=0
void Line::applyCupLineWithRect(float rectX1, float rectY1, float rectX2, float rectY2)
{
    // internal clipping codes
    #define CLIP_CODE_C  0x0000
    #define CLIP_CODE_N  0x0008
    #define CLIP_CODE_S  0x0004
    #define CLIP_CODE_E  0x0002
    #define CLIP_CODE_W  0x0001
        
    #define CLIP_CODE_NE 0x000a
    #define CLIP_CODE_SE 0x0006
    #define CLIP_CODE_NW 0x0009
    #define CLIP_CODE_SW 0x0005
    
    int xc1=x1, yc1=y1, xc2=x2, yc2=y2;
    int p1_code=0, p2_code=0; // 默认在范围内
    
    // determine codes for p1 and p2
    if (y1 < rectY1)
        p1_code|=CLIP_CODE_N;
    else
        if (y1 > rectY2)
            p1_code|=CLIP_CODE_S;
    
    if (x1 < rectX1)
        p1_code|=CLIP_CODE_W;
    else
        if (x1 > rectX2)
            p1_code|=CLIP_CODE_E;
    
    if (y2 < rectY1)
        p2_code|=CLIP_CODE_N;
    else
        if (y2 > rectY2)
            p2_code|=CLIP_CODE_S;
    
    if (x2 < rectX1)
        p2_code|=CLIP_CODE_W;
    else
        if (x2 > rectX2)
            p2_code|=CLIP_CODE_E;
    
    // try and trivially reject
    if ((p1_code & p2_code)) // 同侧
    {
        m_bCanDraw = false;
        return;
    }
    else
    {
        m_bCanDraw = true;
    }
    
    // test for totally visible, if so leave points untouched
    if (p1_code==0 && p2_code==0) // 都在范围内
        return;
    
    // determine end clip point for p1
    switch(p1_code)
    {
        case CLIP_CODE_C: break;
            
        case CLIP_CODE_N:
        {
            yc1 = rectY1;
            xc1 = x1 + 0.5+(rectY2-y1)*(x2-x1)/(y2-y1);
        } break;
        case CLIP_CODE_S:
        {
            yc1 = rectY2;
            xc1 = x1 + 0.5+(rectY2-y1)*(x2-x1)/(y2-y1);
        } break;
            
        case CLIP_CODE_W:
        {
            xc1 = rectX1;
            yc1 = y1 + 0.5+(rectX1-x1)*(y2-y1)/(x2-x1);
        } break;
            
        case CLIP_CODE_E:
        {
            xc1 = rectX2;
            yc1 = y1 + 0.5+(rectX2-x1)*(y2-y1)/(x2-x1);
        } break;
            
            // these cases are more complex, must compute 2 intersections
        case CLIP_CODE_NE:
        {
            // north hline intersection
            yc1 = rectY1;
            xc1 = x1 + 0.5+(rectY1-y1)*(x2-x1)/(y2-y1);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc1 < rectX1 || xc1 > rectX2)
            {
                // east vline intersection
                xc1 = rectX2;
                yc1 = y1 + 0.5+(rectX2-x1)*(y2-y1)/(x2-x1);
            } // end if
            
        } break;
            
        case CLIP_CODE_SE:
        {
            // south hline intersection
            yc1 = rectY2;
            xc1 = x1 + 0.5+(rectY2-y1)*(x2-x1)/(y2-y1);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc1 < rectX1 || xc1 > rectX2)
            {
                // east vline intersection
                xc1 = rectX2;
                yc1 = y1 + 0.5+(rectX2-x1)*(y2-y1)/(x2-x1);
            } // end if
            
        } break;
            
        case CLIP_CODE_NW:
        {
            // north hline intersection
            yc1 = rectY1;
            xc1 = x1 + 0.5+(rectY1-y1)*(x2-x1)/(y2-y1);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc1 < rectX1 || xc1 > rectX2)
            {
                xc1 = rectX1;
                yc1 = y1 + 0.5+(rectX1-x1)*(y2-y1)/(x2-x1);
            } // end if
            
        } break;
            
        case CLIP_CODE_SW:
        {
            // south hline intersection
            yc1 = rectY2;
            xc1 = x1 + 0.5+(rectY2-y1)*(x2-x1)/(y2-y1);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc1 < rectX1 || xc1 > rectX2)
            {
                xc1 = rectX1;
                yc1 = y1 + 0.5+(rectX1-x1)*(y2-y1)/(x2-x1);
            } // end if
            
        } break;
            
        default:break;
            
    } // end switch
    
    // determine clip point for p2
    switch(p2_code)
    {
        case CLIP_CODE_C: break;
            
        case CLIP_CODE_N:
        {
            yc2 = rectY1;
            xc2 = x2 + (rectY1-y2)*(x1-x2)/(y1-y2);
        } break;
            
        case CLIP_CODE_S:
        {
            yc2 = rectY2;
            xc2 = x2 + (rectY2-y2)*(x1-x2)/(y1-y2);
        } break;
            
        case CLIP_CODE_W:
        {
            xc2 = rectX1;
            yc2 = y2 + (rectX1-x2)*(y1-y2)/(x1-x2);
        } break;
            
        case CLIP_CODE_E:
        {
            xc2 = rectX2;
            yc2 = y2 + (rectX2-x2)*(y1-y2)/(x1-x2);
        } break;
            
            // these cases are more complex, must compute 2 intersections
        case CLIP_CODE_NE:
        {
            // north hline intersection
            yc2 = rectY1;
            xc2 = x2 + 0.5+(rectY1-y2)*(x1-x2)/(y1-y2);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc2 < rectX1 || xc2 > rectX2)
            {
                // east vline intersection
                xc2 = rectX2;
                yc2 = y2 + 0.5+(rectX2-x2)*(y1-y2)/(x1-x2);
            } // end if
            
        } break;
            
        case CLIP_CODE_SE:
        {
            // south hline intersection
            yc2 = rectY2;
            xc2 = x2 + 0.5+(rectY2-y2)*(x1-x2)/(y1-y2);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc2 < rectX1 || xc2 > rectX2)
            {
                // east vline intersection
                xc2 = rectX2;
                yc2 = y2 + 0.5+(rectX2-x2)*(y1-y2)/(x1-x2);
            } // end if
            
        } break;
            
        case CLIP_CODE_NW:
        {
            // north hline intersection
            yc2 = rectY1;
            xc2 = x2 + 0.5+(rectY1-y2)*(x1-x2)/(y1-y2);
            
            // test if intersection is valid, of so then done, else compute next
            if (xc2 < rectX1 || xc2 > rectX2)
            {
                xc2 = rectX1;
                yc2 = y2 + 0.5+(rectX1-x2)*(y1-y2)/(x1-x2);
            } // end if
            
        } break;
            
        case CLIP_CODE_SW:
        {
            // south hline intersection
            yc2 = rectY2;
            xc2 = x2 + 0.5+(rectY2-y2)*(x1-x2)/(y1-y2);	
            
            // test if intersection is valid, of so then done, else compute next
            if (xc2 < rectX1 || xc2 > rectX2)
            {
                xc2 = rectX1;
                yc2 = y2 + 0.5+(rectX1-x2)*(y1-y2)/(x1-x2);	
            } // end if
            
        } break;
            
        default:break;
            
    } // end switch
    
    // do bounds check
    if ((xc1 < rectX1) || (xc1 > rectX2) ||
        (yc1 < rectY1) || (yc1 > rectY2) ||
        (xc2 < rectX1) || (xc2 > rectX2) ||
        (yc2 < rectY1) || (yc2 > rectY2) )
    {
        return;
    } // end if
    
    // store vars back
    x1 = xc1;
    y1 = yc1;
    x2 = xc2;
    y2 = yc2;
}
























