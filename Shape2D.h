// William Jeremy James

#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "Point2D.h"
#include <vector>

class Shape2D
{
private:
    // Private Variables
    Point2D CenterPoint;
    std::vector<Point2D> Shape;

public:
    // Constructors
    Shape2D() : Shape2D(Point2D(), std::vector<Point2D>()) {}
    Shape2D(const Point2D& centerPoint, const std::vector<Point2D>& shape)
    {
        setCenterPoint(centerPoint);
        setShape(shape);
    }

    // Accessors
    Point2D getCenterPoint(void) const
    {
        return CenterPoint;
    }
    std::vector<Point2D> getShape(void) const
    {
        return Shape;
    }

    // Mutators
    void setCenterPoint(Point2D centerPoint)
    {
        CenterPoint = centerPoint;
    }
    void setShape(std::vector<Point2D> shape)
    {
        Shape.clear();
        Shape = shape;
    }

};

#endif