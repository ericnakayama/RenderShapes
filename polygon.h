#include "shape.h"

#ifndef POLYGON_H
#define POLYGON_H

class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polygon} {}
    ~Polygon() override { }

    void set_point(const QPoint& point);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

#endif