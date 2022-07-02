#include "Circle.h"
#include <stdio.h>

/*virtual function*/
static uint32_t Circle_area_(Shape const * const me);
static void Circle_draw_(Shape const * const me);

/*constructor*/
void Circle_ctor(Circle* const me, int16_t x, int16_t y,
                    uint16_t radius)
{
    static struct ShapeVtbl const vtbl =
    {
        Circle_area_,
        Circle_draw_
    };
    Shape_ctor(&me->super, x, y);/*call base class constrcutor*/
    me->super.vptr = &vtbl;
    me->radius = radius;
}


/*virtual function implement*/
static uint32_t Circle_area_(Shape const * const me)
{
    Circle const * const me_ = (Circle const *)me;
    return (uint32_t)me_->radius * (uint32_t)me_->radius * 3;

}
static void Circle_draw_(Shape const * const me)
{

    Circle const * const me_ = (Circle const *)me;
    printf("Circle draw(x=%d, y=%d, radius=%d)\n", Shape_getX(me), Shape_getY(me),(uint32_t)me_->radius);
}
