// William Jeremy James

#ifndef ROBOT_H
#define ROBOT_H

#include "Rectangle.h"
#include <cmath>

class Robot : public Rectangle
{
private:
    // Private Constants
    const double PI = std::acos(-1);

    // Private Variables
    Point2D OffsetXY, StartingLocation, CurrentLocation;    // Inches
    double CurrentAngle;                                    // Degree

public:
    // Public Constructor
    Robot() {}

    // Public Accessors
    Point2D getOffsetXY(void) const
    {
        return OffsetXY;
    }
    Point2D getStartingLocation(void) const
    {
        return StartingLocation;
    }
    Point2D getCurrentLocation(void) const
    {
        return CurrentLocation;
    }
    double getCurrentAngle(void) const
    {
        return CurrentAngle;
    }

    // Public Mutators
    void setOffsetXY(const Point2D& offsetXY)
    {
        OffsetXY = offsetXY;
    }
    void setStartingLocation()
    {
        StartingLocation = Point2D((getWidth() / 2) + OffsetXY.getX(), (getLength() / 2) + OffsetXY.getY());
    }
    void setCurrentLocation(const Point2D& currentLocation)
    {
        CurrentLocation = currentLocation;
    }
    void setCurrentAngle(const double& currentAngle)
    {
        CurrentAngle = currentAngle;
    }

    // Public Functions
    void updateShape(void)
    {
        std::vector<Point2D> shape, newShape;
        setCenterPoint(CurrentLocation);
        double radian = getCurrentAngle() * PI / 180.0;
        double radius = std::sqrt(std::pow((getLength() / 2.0), 2.0) + std::pow((getWidth() / 2.0), 2.0));

        // Unrotated Points
        shape.push_back(Point2D(getCenterPoint().getX() + (getLength() / 2.0), getCenterPoint().getY() + (getWidth() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() + (getLength() / 2.0), getCenterPoint().getY() - (getWidth() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() - (getLength() / 2.0), getCenterPoint().getY() - (getWidth() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() - (getLength() / 2.0), getCenterPoint().getY() + (getWidth() / 2.0)));
        shape.push_back(Point2D(getCenterPoint().getX() + (getLength() / 2.0), getCenterPoint().getY() + (getWidth() / 2.0)));
        
        // Rotate Points
        for (Point2D point : shape)
        {
            double x, y;
            double angle = atan2(point.getY() - getCenterPoint().getY(), point.getX() - getCenterPoint().getX()) * 180.0 / PI + getCurrentAngle();
            if (angle < 0.0)
            {
                angle += 360.0;
            }
            if (angle > 360.0)
            {
                angle -= 360.0;
            }
            x = radius * std::cos(angle * PI / 180.0) + getCenterPoint().getX();
            y = radius * std::sin(angle * PI / 180.0) + getCenterPoint().getY();
            newShape.push_back(Point2D(x, y));
        }

        // Set Shape
        setShape(newShape);
    }
    
};

#endif