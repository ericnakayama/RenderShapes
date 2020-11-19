#include <iostream>
#include <string>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    enum class ShapeType { NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text };

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

class Line : public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Line} {}
    ~Line() override { }
    
    void set_points(const QPoint& point_begin, const QPoint& point_end);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QPoint point_begin;
    QPoint point_end;
};

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
    ~Polyline() override { }
    
    void set_point(const QPoint& point);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

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

class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} {}
    ~Rectangle() override { }


private:

};

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} {}
    ~Ellipse() override { }

private:


};

class Text : public Shape
{
public:
    Text(QPaintDevice * device = nullptr, int id = -1) : Shape{device, id, ShapeType::Text} { }
    ~Text() override { }

private:


};

#endif