#include "Rectangle.h"
#include <stdio.h>

/*virtual function*/
static uint32_t Rectangle_area_(Shape const * const me);
static void Rectangle_draw_(Shape const * const me);

/*constructor*/
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height)
{
    static struct ShapeVtbl const vtbl =
    {
        Rectangle_area_,
        Rectangle_draw_
    };
    Shape_ctor(&me->super, x, y);/*call base class constrcutor*/
    me->super.vptr = &vtbl;
    me->width = width;
    me->height = height;
}


/*virtual function implement*/
static uint32_t Rectangle_area_(Shape const * const me)
{
    Rectangle const * const me_ = (Rectangle const *)me;
    return (uint32_t)me_->width * (uint32_t)me_->height;

}
static void Rectangle_draw_(Shape const * const me)
{

    Rectangle const * const me_ = (Rectangle const *)me;
    printf("Rectangle draw(x=%d, y=%d, width=%d, height=%d)\n", Shape_getX(me), Shape_getY(me),(uint32_t)me_->width , (uint32_t)me_->height);
}
