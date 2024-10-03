// William Jeremy James

#ifndef TARGETAREA_H
#define TARGETAREA_H

#include "Point2D.h"
#include "Shape2D.h"
#include <cmath>
#include <vector>

class TargetArea : public Shape2D
{
private:
    // Private Constants
    const double FIELD_LENGTH = 8.0 * 12.0, FIELD_WIDTH = 8.0 * 12.0;               // Inches
    const double PI = std::acos(-1);

    // Private Variables
    bool IsInnerCircle;
    int FieldCorner;
    double Radius, InnerCircleRadius;
    std::vector<Point2D> FireRegionShape;

public:
    // Public Constructor
    TargetArea() {}
    
    // Public Accessors
    int getFieldCorner(void) const
    {
        return FieldCorner;
    }
    double getRadius(void) const
    {
        return Radius;
    }
    bool getIsInnerCircle(void) const
    {
        return IsInnerCircle;
    }
    double getInnerCircleRadius(void) const
    {
        return InnerCircleRadius;
    }
    std::vector<Point2D> getFireRegionShape(void) const
    {
        return FireRegionShape;
    }

    // Public Mutators
    void setFieldCorner(const int& fieldCorner)
    {
        FieldCorner = fieldCorner;
    }
    void setRadius(const double& radius)
    {
        Radius = radius;
    }
    void setIsInnerCircle(const bool& isInnerCircle)
    {
        IsInnerCircle = isInnerCircle;
    }
    void setInnerCircleRadius(const double& innerCircleRadius)
    {
        InnerCircleRadius = innerCircleRadius;
    }
    void setFireRegionShape(const std::vector<Point2D> fireRegionShape)
    {
        // Clear And Resize Vector
        FireRegionShape.clear();
        FireRegionShape.resize(5);

        // Set Vector
        for (int index = 0; index < 5; index++) { FireRegionShape[index] = fireRegionShape[index]; };
    }

    // Public Functions
    void updateShape(void)
    {
        // Local Variables
        std::vector<Point2D> shape;
        double firstDegree, lastDegree, X, Y;

        if (IsInnerCircle) {
            // Inner Circle
            switch (FieldCorner)
            {
            // Top-Left Field Corner
            case 0 :
                shape.push_back(FireRegionShape[1]);
                shape.push_back(FireRegionShape[2]);
                shape.push_back(FireRegionShape[3]);
                for (int index = 181; index < 450; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index; 
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y)); 
                }
                shape.push_back(FireRegionShape[1]);
                break;

            // Top-Right Field Corner
            case 1 :
                shape.push_back(FireRegionShape[2]);
                shape.push_back(FireRegionShape[3]);
                shape.push_back(FireRegionShape[0]);
                for (int index = 91; index < 360; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index; 
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y)); 
                }
                shape.push_back(FireRegionShape[2]);
                break;
            
            // Bottom-Right Field Corner
            case 2 :
                shape.push_back(FireRegionShape[3]);
                shape.push_back(FireRegionShape[0]);
                shape.push_back(FireRegionShape[1]);
                for (int index = 1; index < 270; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index; 
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y)); 
                }
                shape.push_back(FireRegionShape[3]);
                break;

            // Bottom-Left Field Corner
            case 3 :
                shape.push_back(FireRegionShape[0]);
                shape.push_back(FireRegionShape[1]);
                shape.push_back(FireRegionShape[2]);
                for (int index = 271; index < 540; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index; 
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y)); 
                }
                shape.push_back(FireRegionShape[0]);
                break;
            }
        } else {
            // Outer Circle
            switch (FieldCorner)
            {
            // Top-Left Field Corner
            case 0 :
                shape.push_back(FireRegionShape[3]);
                for (int index = 181; index < 450; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index; 
                    double radian = degree * PI / 180;
                    double x, y;
                    x = InnerCircleRadius * std::cos(radian) + getCenterPoint().getX();
                    y = InnerCircleRadius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y)); 
                }
                shape.push_back(FireRegionShape[1]); 

                firstDegree = (std::asin((FIELD_LENGTH - getCenterPoint().getY()) / Radius) * 180 / PI) + 360;
                X = Radius * std::cos(firstDegree * PI / 180) + getCenterPoint().getX();               
                lastDegree = 360 - (std::acos((0 - getCenterPoint().getX()) / Radius) * 180 / PI);
                Y = Radius * std::sin(lastDegree * PI / 180) + getCenterPoint().getY();  
                
                shape.push_back(Point2D(X, FIELD_LENGTH));
                for (int index = firstDegree; index > lastDegree; index--)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index; 
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(Point2D(0, Y));
                shape.push_back(FireRegionShape[3]);
                break;

            // Top-Right Field Corner
            case 1 :
                shape.push_back(FireRegionShape[0]);
                for (int index = 91; index < 360; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index;
                    double radian = degree * PI / 180;
                    double x, y;
                    x = InnerCircleRadius * std::cos(radian) + getCenterPoint().getX();
                    y = InnerCircleRadius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(FireRegionShape[2]);

                firstDegree = 360 - (std::acos((FIELD_WIDTH - getCenterPoint().getX()) / Radius) * 180 / PI);
                Y = Radius * std::sin(firstDegree * PI / 180) + getCenterPoint().getY();
                lastDegree = 180 - (std::asin((FIELD_LENGTH - getCenterPoint().getY()) / Radius) * 180 / PI);
                X = Radius * std::cos(lastDegree * PI / 180) + getCenterPoint().getX();

                shape.push_back(Point2D(FIELD_WIDTH, Y));
                for (int index = firstDegree; index > lastDegree; index--)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index;
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(Point2D(X, FIELD_LENGTH));
                shape.push_back(FireRegionShape[0]);                
                break;

            // Bottom-Right Field Corner
            case 2 :
                shape.push_back(FireRegionShape[1]);
                for (int index = 1; index < 270; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index;
                    double radian = degree * PI / 180;
                    double x, y;
                    x = InnerCircleRadius * std::cos(radian) + getCenterPoint().getX();
                    y = InnerCircleRadius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(FireRegionShape[3]);

                firstDegree = (std::asin((FIELD_WIDTH - getCenterPoint().getX()) / Radius) * 180 / PI) + 180;
                X = Radius * std::cos(firstDegree * PI / 180) + getCenterPoint().getX();
                lastDegree = 180 - (std::acos((0 - getCenterPoint().getY()) / Radius) * 180 / PI);
                Y = Radius * std::sin(lastDegree * PI / 180) + getCenterPoint().getY();

                shape.push_back(Point2D(X, 0));
                for (int index = firstDegree; index > lastDegree; index--)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index;
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(Point2D(FIELD_WIDTH, Y));
                shape.push_back(FireRegionShape[1]);                
                break;

            // Bottom-Left Field Corner
            case 3 :
                shape.push_back(FireRegionShape[2]);
                for (int index = 271; index < 540; index++)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index;
                    double radian = degree * PI / 180;
                    double x, y;
                    x = InnerCircleRadius * std::cos(radian) + getCenterPoint().getX();
                    y = InnerCircleRadius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(FireRegionShape[0]);

                firstDegree = (std::acos((0 - getCenterPoint().getY()) / Radius) * 180 / PI);
                Y = Radius * std::sin(firstDegree * PI / 180) + getCenterPoint().getY();
                lastDegree = (std::asin((0 - getCenterPoint().getX()) / Radius) * 180 / PI);
                X = Radius * std::cos(lastDegree * PI / 180) + getCenterPoint().getX();
                
                shape.push_back(Point2D(0, Y));
                for (int index = firstDegree; index > lastDegree; index--)
                {
                    double degree;
                    index > 360 ? degree = index - 360 : degree = index;
                    double radian = degree * PI / 180;
                    double x, y;
                    x = Radius * std::cos(radian) + getCenterPoint().getX();
                    y = Radius * std::sin(radian) + getCenterPoint().getY();
                    shape.push_back(Point2D(x, y));
                }
                shape.push_back(Point2D(X, 0));
                shape.push_back(FireRegionShape[2]);                
                break;
            }
        }
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