#include "shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
    Circle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Circle} {}
    ~Circle() override { }

private:


};

#endif