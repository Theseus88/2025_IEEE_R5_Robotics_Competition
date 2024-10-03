// William Jeremy James

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape2D.h"

class Rectangle : public Shape2D
{
private:
    // Private Variables
    double Length, Width;

public:
    // Constructors
    Rectangle() : Rectangle(0.0, 0.0) {}
    Rectangle(const double& length, const double& width)
    {
        setLength(length);
        setWidth(width);
    }

    // Accessors
    double getLength(void) const
    {
        return Length;
    }
    double getWidth(void) const
    {
        return Width;
    }

    // Mutators
    void setLength(const double& length)
    {
        Length = length;
    }
    void setWidth(const double& width)
    {
        Width = width;
    }
};

#endif