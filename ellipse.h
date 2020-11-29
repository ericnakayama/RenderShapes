#include "shape.h"

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} {}
    ~Ellipse() override { }

private:


};

#endif