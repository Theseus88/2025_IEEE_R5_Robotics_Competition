// William Jeremy James

#ifndef LATCH_H
#define LATCH_H

#include "Rectangle.h"

class Latch : public Rectangle
{
private:
    // Private Variables
    double Height;
    
public:
    // Public Constructor
    Latch() {}
    
    // Public Accessors
    double getHeight(void) const
    {
        return Height;
    }

    // Public Mutators
    void setHeight(const double& height)
    {
        Height = height;
    }

    // Public Functions
    void updateShape(void)
    {
        std::vector<Point2D> shape;
        shape.push_back(Point2D(getCenterPoint().getX() - (getWidth() / 2.0), getCenterPoint().getY() + (getLength() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() + (getWidth() / 2.0), getCenterPoint().getY() + (getLength() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() + (getWidth() / 2.0), getCenterPoint().getY() - (getLength() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() - (getWidth() / 2.0), getCenterPoint().getY() - (getLength() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() - (getWidth() / 2.0), getCenterPoint().getY() + (getLength() / 2.0)));
        setShape(shape);
    }
};

#endif