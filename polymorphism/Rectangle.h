/*
继承就是基于现有的一个类去定义一个新类，这样有助于重用代码，更好的组织代码。在 C 语言里面，去实现单继承也非常简单，只要把基类放到继承类的第一个数据成员的位置就行了

*/
#ifndef RECT_H
#define RECT_H

#include "Shape.h" // 基类接口

// 矩形的属性
typedef struct {
    Shape super; // 继承 Shape

    // 自己的属性
    uint16_t width;
    uint16_t height;
} Rectangle;

// 构造函数
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height);

#endif /* RECT_H */

