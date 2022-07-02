#include "Rectangle.h"
#include "Circle.h"
#include <stdio.h>

int main()
{
    Rectangle r1, r2;
    Circle c1, c2;

    Shape const *Shapes[] =
    {
        &r1.super,
        &r2.super,
        &c1.super,
        &c2.super
    };

    Shape const *s;

    //instantiation
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);
    Circle_ctor(&c1, 2, 30, 25);
    Circle_ctor(&c2, 0, -4, 3);

    s = largestShape(Shapes, sizeof(Shapes)/sizeof(Shapes[0]));
    printf("largestsShape s (x=%d, y=%d)\n", Shape_getX(s), Shape_getY(s));

    drawAllShapes(Shapes,sizeof(Shapes)/sizeof(Shapes[0]));
    return 0;
}
