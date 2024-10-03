// William Jeremy James

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D
{
private:
    // Private Variables
    double X, Y;

public:
    // Constructors
    Point2D() : Point2D(0.0, 0.0) {}
    Point2D(const double& x, const double& y)
    {
        setX(x);
        setY(y);
    }

    // Accessors
    double getX(void) const
    {
        return X;
    }
    double getY(void) const
    {
        return Y;
    }

    // Mutators
    void setX(const double& x)
    {
        X = x;
    }
    void setY(const double& y)
    {
        Y = y;
    }

    // Overloaded Operators
    friend std::ostream& operator <<(std::ostream& stream, Point2D& point2D)
    {
        stream << point2D.X << "," << point2D.Y;
        return stream;
    };
    friend std::istream& operator >>(std::istream& stream, Point2D& point2D)
    {
        stream >> point2D.X >> point2D.Y;
        return stream;
    };
};

#endif