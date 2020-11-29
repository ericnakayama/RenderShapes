#include "shape.h"

Shape::Shape(QPaintDevice* device, int id, ShapeType shape)
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

QPainter& Shape::get_qpainter()
{
    return qpainter;
}

Shape::ShapeType Shape::get_shape() const
{
    return shape;
}

const QPen& Shape::get_pen() const
{
    return pen;
}

const QBrush& Shape::get_brush() const
{
    return brush;
}