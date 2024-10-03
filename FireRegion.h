// William Jeremy James

#ifndef FIREREGION_H
#define FIREREGION_H

#include "Point2D.h"
#include "Rectangle.h"
#include "Shape2D.h"
#include <vector>

class FireRegion : public Rectangle
{
public:
    // Constructors
    FireRegion() : FireRegion(Point2D(), 0.0, 0.0) {}
    FireRegion(const Point2D& centerPoint, const double& length, const double& width)
    {
        setCenterPoint(centerPoint);
        setLength(length);
        setWidth(width);
        updateShape();
    }

    // Public Functions
    void updateShape(void)
    {
        std::vector<Point2D> shape;
        shape.push_back(Point2D(getCenterPoint().getX() - (getWidth() / 2), getCenterPoint().getY() + (getLength() / 2)));
        shape.push_back(Point2D(getCenterPoint().getX() + (getWidth() / 2), getCenterPoint().getY() + (getLength() / 2)));
        shape.push_back(Point2D(getCenterPoint().getX() + (getWidth() / 2), getCenterPoint().getY() - (getLength() / 2)));
        shape.push_back(Point2D(getCenterPoint().getX() - (getWidth() / 2), getCenterPoint().getY() - (getLength() / 2)));
        shape.push_back(Point2D(getCenterPoint().getX() - (getWidth() / 2), getCenterPoint().getY() + (getLength() / 2)));
        setShape(shape);
    }
    bool checkIfInside(const Point2D& point)
    {
        std::vector<Point2D> polygon = getShape();
        if (polygon.size() < 3) {
            return false;
        }

        // Ray Casting Algorithm
        int intersections = 0;
        for (int index0 = 0, index1 = polygon.size() - 1; index0 < polygon.size(); index1 = index0++) {
            if ((polygon[index0].getY() <= point.getY() && polygon[index1].getY() > point.getY()) ||
                (polygon[index0].getY() > point.getY() && polygon[index1].getY() <= point.getY())) {
                if (point.getX() < (polygon[index1].getX() - polygon[index0].getX()) * (point.getY() - polygon[index0].getY()) / (polygon[index1].getY() - polygon[index0].getY()) + polygon[index0].getX()) {
                    intersections++;
                }
            } else if (polygon[index0].getY() == point.getY() && polygon[index1].getY() == point.getY() && point.getX() >= polygon[index0].getX() && point.getX() <= polygon[index1].getX()) {
                intersections++;
            }
        }

        // Return True If Point Is Inside The Polygon
        return intersections % 2 == 1;
    }
    
};

#endif