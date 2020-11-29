#include "shape.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape
{
public:
    Square(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Square} {}
    Square() override { }


private:

};

#endif