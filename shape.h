#include <iostream>
#include <string>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    enum class ShapeType { NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text };

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::noShape);
    virtual ~Shape() {}

    // add deleted copy operations

    ShapeType get_shape() const;
    const QPen& get_pen() const;
    const QBrush& get_brush() const;

    void set_shape(ShapeType shape);
    void set_pen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void set_pen(Qt::GlobalColor);
    void set_brush(Qt::GlobalColor, Qt::BrushStyle);

    void default_style();
    void draw_rect(int width, int height);

    virtual void draw(const int translate_x, const int translate_y) = 0;

protected:
    QPainter& get_qpainter();

private:
    QPainter qpainter;

    int id;
    ShapeType shape;
    QPen pen;
    Qbrush brush;

};

#endif