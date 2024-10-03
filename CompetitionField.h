// William Jeremy James

#ifndef COMPETITIONFIELD_H
#define COMPETITIONFIELD_H

#include "FireRegion.h"
#include "Latch.h"
#include "Point2D.h"
#include "Robot.h"
#include "TargetArea.h"
#include "TreeObstacle.h"
#include <vector>
#include <cmath>

class CompetitionField
{
private:
    // Private Constants
    const double FIELD_LENGTH = 8.0 * 12.0, FIELD_WIDTH = 8.0 * 12.0;                                       // Inches
    const double FIRE_REGION_LENGTH = 1.5 * 12.0, FIRE_REGION_WIDTH = 1.5 * 12.0;                           // Inches
    const double BAND_ONE_RADIUS = 1.5 * 12.0, BAND_TWO_RADIUS = 2.5 * 12.0;                                // Inches
    const double FIREHOSE_LATCH_LENGTH = 0.5, FIREHOSE_LATCH_WIDTH = 6.0, FIREHOSE_LATCH_HEIGHT = 1.0;      // Inches
    const double FIREHOSE_LATCH_FROM_LEFT_WALL = 1.5 * 12.0, FIREHOSE_LATCH_FROM_REAR_WALL = 5.0 * 12.0;    // Inches
    const double TREE_OBSTACLE_DIAMETER = 1.0, TREE_OBSTACLE_ADDITIONAL_BUFFER = 1.0;                       // Inches
    const double START_FROM_LEFT_WALL = 0.5 * 12.0, START_FROM_REAR_WALL = 2.0;                             // Inches 
    const double ROBOT_LENGTH = 9.0, ROBOT_WIDTH = 5.0, STARTING_ANGLE = 90.0;                              // Inches
    const double PI = std::acos(-1);                                                                        // Unitless

    // Private Variables
    std::vector<FireRegion> PotentialFireRegions;
    std::vector<TargetArea> PotentialTargetAreas;
    std::vector<TreeObstacle> Obstacles;
    Latch FirehoseLatch;
    Robot MyRobot;

    // Private Mutators
    void setPotentialFireRegions(void)
    {
        // Resize PotentialFireRegions Vector
        PotentialFireRegions.resize(4);

        // Top-Left Field Corner
        PotentialFireRegions[0].setCenterPoint(Point2D((FIRE_REGION_WIDTH / 2.0), (FIELD_LENGTH - (FIRE_REGION_LENGTH / 2.0))));
        PotentialFireRegions[0].setLength(FIRE_REGION_LENGTH);
        PotentialFireRegions[0].setWidth(FIRE_REGION_WIDTH);
        PotentialFireRegions[0].updateShape();

        // Top-Right Field Corner
        PotentialFireRegions[1].setCenterPoint(Point2D((FIELD_WIDTH - (FIRE_REGION_WIDTH / 2.0)), (FIELD_LENGTH - (FIRE_REGION_LENGTH / 2.0))));
        PotentialFireRegions[1].setLength(FIRE_REGION_LENGTH);
        PotentialFireRegions[1].setWidth(FIRE_REGION_WIDTH);
        PotentialFireRegions[1].updateShape();

        // Bottom-Right Field Corner
        PotentialFireRegions[2].setCenterPoint(Point2D((FIELD_WIDTH - (FIRE_REGION_WIDTH / 2.0)), (FIRE_REGION_LENGTH / 2.0)));
        PotentialFireRegions[2].setLength(FIRE_REGION_LENGTH);
        PotentialFireRegions[2].setWidth(FIRE_REGION_WIDTH);
        PotentialFireRegions[2].updateShape();

        // Bottom-Left Field Corner
        PotentialFireRegions[3].setCenterPoint(Point2D((FIRE_REGION_WIDTH / 2.0), (FIRE_REGION_LENGTH / 2.0)));
        PotentialFireRegions[3].setLength(FIRE_REGION_LENGTH);
        PotentialFireRegions[3].setWidth(FIRE_REGION_WIDTH);
        PotentialFireRegions[3].updateShape();
    }
    void setPotentialTargetAreas(void)
    {
        // Resize PotentialTargetAreas Vector
        PotentialTargetAreas.resize(8);

        // Top-Left Field Corner
        PotentialTargetAreas[0].setCenterPoint(Point2D(FIRE_REGION_WIDTH, FIELD_LENGTH - FIRE_REGION_LENGTH));
        PotentialTargetAreas[0].setFieldCorner(0);
        PotentialTargetAreas[0].setRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[0].setFireRegionShape(PotentialFireRegions[0].getShape());
        PotentialTargetAreas[0].updateShape();

        PotentialTargetAreas[1].setCenterPoint(Point2D(FIRE_REGION_WIDTH, FIELD_LENGTH - FIRE_REGION_LENGTH));
        PotentialTargetAreas[1].setFieldCorner(0);
        PotentialTargetAreas[1].setRadius(BAND_TWO_RADIUS);
        PotentialTargetAreas[1].setFireRegionShape(PotentialFireRegions[0].getShape());
        PotentialTargetAreas[1].setIsInnerCircle(false);
        PotentialTargetAreas[1].setInnerCircleRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[1].updateShape();

        // Top-Right Field Corner
        PotentialTargetAreas[2].setCenterPoint(Point2D(FIELD_WIDTH - FIRE_REGION_WIDTH, FIELD_LENGTH - FIRE_REGION_LENGTH));
        PotentialTargetAreas[2].setFieldCorner(1);
        PotentialTargetAreas[2].setRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[2].setFireRegionShape(PotentialFireRegions[1].getShape());
        PotentialTargetAreas[2].updateShape();

        PotentialTargetAreas[3].setCenterPoint(Point2D(FIELD_WIDTH - FIRE_REGION_WIDTH, FIELD_LENGTH - FIRE_REGION_LENGTH));
        PotentialTargetAreas[3].setFieldCorner(1);
        PotentialTargetAreas[3].setRadius(BAND_TWO_RADIUS);
        PotentialTargetAreas[3].setFireRegionShape(PotentialFireRegions[1].getShape());
        PotentialTargetAreas[3].setIsInnerCircle(false);
        PotentialTargetAreas[3].setInnerCircleRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[3].updateShape();

        // Bottom-Right Field Corner
        PotentialTargetAreas[4].setCenterPoint(Point2D(FIELD_WIDTH - FIRE_REGION_WIDTH, FIRE_REGION_LENGTH));
        PotentialTargetAreas[4].setFieldCorner(2);
        PotentialTargetAreas[4].setRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[4].setFireRegionShape(PotentialFireRegions[2].getShape());
        PotentialTargetAreas[4].updateShape();

        PotentialTargetAreas[5].setCenterPoint(Point2D(FIELD_WIDTH - FIRE_REGION_WIDTH, FIRE_REGION_LENGTH));
        PotentialTargetAreas[5].setFieldCorner(2);
        PotentialTargetAreas[5].setRadius(BAND_TWO_RADIUS);
        PotentialTargetAreas[5].setFireRegionShape(PotentialFireRegions[2].getShape());
        PotentialTargetAreas[5].setIsInnerCircle(false);
        PotentialTargetAreas[5].setInnerCircleRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[5].updateShape();

        // Bottom-Left Field Corner
        PotentialTargetAreas[6].setCenterPoint(Point2D(FIRE_REGION_WIDTH, FIRE_REGION_LENGTH));
        PotentialTargetAreas[6].setFieldCorner(3);
        PotentialTargetAreas[6].setRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[6].setFireRegionShape(PotentialFireRegions[3].getShape());
        PotentialTargetAreas[6].updateShape();

        PotentialTargetAreas[7].setCenterPoint(Point2D(FIRE_REGION_WIDTH, FIRE_REGION_LENGTH));
        PotentialTargetAreas[7].setFieldCorner(3);
        PotentialTargetAreas[7].setRadius(BAND_TWO_RADIUS);
        PotentialTargetAreas[7].setFireRegionShape(PotentialFireRegions[3].getShape());
        PotentialTargetAreas[7].setIsInnerCircle(false);
        PotentialTargetAreas[7].setInnerCircleRadius(BAND_ONE_RADIUS);
        PotentialTargetAreas[7].updateShape();
    }
    void setFirehoseLatch(void)
    {
        FirehoseLatch.setLength(FIREHOSE_LATCH_LENGTH);
        FirehoseLatch.setWidth(FIREHOSE_LATCH_WIDTH);
        FirehoseLatch.setHeight(FIREHOSE_LATCH_HEIGHT);
        FirehoseLatch.setCenterPoint(Point2D((FIREHOSE_LATCH_WIDTH / 2.0) + FIREHOSE_LATCH_FROM_LEFT_WALL, (FIREHOSE_LATCH_LENGTH / 2.0) + FIREHOSE_LATCH_FROM_REAR_WALL));
        FirehoseLatch.updateShape();
    }
    void setMyRobot(void)
    {
        MyRobot.setLength(ROBOT_LENGTH);
        MyRobot.setWidth(ROBOT_WIDTH);
        MyRobot.setOffsetXY(Point2D(START_FROM_LEFT_WALL, START_FROM_REAR_WALL));
        MyRobot.setStartingLocation();
        MyRobot.setCurrentLocation(MyRobot.getStartingLocation());
        MyRobot.setCurrentAngle(STARTING_ANGLE);
        MyRobot.updateShape();
    }

public:
    // Public Constructor
    CompetitionField()
    {
        setPotentialFireRegions();
        setPotentialTargetAreas();
        clearObstacles();
        setFirehoseLatch();
        setMyRobot();
    }

    // Public Accessors
    std::vector<FireRegion> getPotentialFireRegions(void) const
    {
        return PotentialFireRegions;
    }
    std::vector<TargetArea> getPotentialTargetAreas(void) const
    {
        return PotentialTargetAreas;
    }
    Latch getFirehoseLatch(void) const
    {
        return FirehoseLatch;
    }
    Robot getMyRobot(void) const
    {
        return MyRobot;
    }

    // Public Mutators
    void setObstacles(const std::vector<TreeObstacle>& obstacles)
    {
        Obstacles.clear();
        Obstacles = obstacles;
    }
    
    // Public Functions
    int checkIfInside(void)
    {
        int index = 0;
        for (FireRegion region : PotentialFireRegions)
        {
            if (region.checkIfInside(MyRobot.getCurrentLocation()))
            {
                return index;
            }
            index++;
        }
        for (TargetArea area : PotentialTargetAreas)
        {
            if (area.checkIfInside(MyRobot.getCurrentLocation()))
            {
                return index;
            }
            index++;
        }
        return index;
    }
    double getAngleTo(const Point2D& point)
    {
        // Calculate the difference in x and y coordinates.
        double dx = point.getX() - MyRobot.getCurrentLocation().getX();
        double dy = point.getY() - MyRobot.getCurrentLocation().getY();

        // Calculate the angle in radians using atan2 to handle quadrant issues.
        double radians = std::atan2(dy, dx);

        // Convert the angle to degrees if needed.
        double degrees = radians * 180.0 / PI;

        // Normalize the angle to the range of 0 to 360 degrees
        if (degrees < 0) {
            degrees += 360;
        }
        if (degrees > 360) {
            degrees -= 360;
        }

        return degrees;
    }
    double getDistanceTo(const Point2D& point)
    {
        // Calculate the difference in x and y coordinates.
        double dx = point.getX() - MyRobot.getCurrentLocation().getX();
        double dy = point.getY() - MyRobot.getCurrentLocation().getY();

        return std::sqrt(std::pow(dx, 2.0) + std::pow(dy, 2.0));
    }
    void moveForwards(const double& distance)
    {
        // Calculate the new x and y coordinates using trigonometry
        double x = MyRobot.getCurrentLocation().getX() + distance * std::cos(MyRobot.getCurrentAngle() * PI / 180);
        double y = MyRobot.getCurrentLocation().getY() + distance * std::sin(MyRobot.getCurrentAngle() * PI / 180);

        // Update the CurrentLocation and shape
        MyRobot.setCurrentLocation(Point2D(x, y));
        MyRobot.updateShape();
    }
    void moveBackwards(const double& distance)
    {
        // Calculate the new x and y coordinates using trigonometry
        double x = MyRobot.getCurrentLocation().getX() - distance * std::cos(MyRobot.getCurrentAngle() * PI / 180);
        double y = MyRobot.getCurrentLocation().getY() - distance * std::sin(MyRobot.getCurrentAngle() * PI / 180);

        // Update the CurrentLocation and shape
        MyRobot.setCurrentLocation(Point2D(x, y));
        MyRobot.updateShape();
    }
    void moveLeft(const double& distance)       // Primarily Used By Robots Utilizing Mecanum Wheels...
    {
        double angle = MyRobot.getCurrentAngle() + 90;
        // Calculate the new x and y coordinates using trigonometry
        double x = MyRobot.getCurrentLocation().getX() + distance * std::cos(angle * PI / 180);
        double y = MyRobot.getCurrentLocation().getY() + distance * std::sin(angle * PI / 180);

        // Update the CurrentLocation and shape
        MyRobot.setCurrentLocation(Point2D(x, y));
        MyRobot.updateShape();
    }
    void moveRight(const double& distance)      // Primarily Used By Robots Utilizing Mecanum Wheels...
    {
        double angle = MyRobot.getCurrentAngle() - 90;
        // Calculate the new x and y coordinates using trigonometry
        double x = MyRobot.getCurrentLocation().getX() + distance * std::cos(angle * PI / 180);
        double y = MyRobot.getCurrentLocation().getY() + distance * std::sin(angle * PI / 180);

        // Update the CurrentLocation and shape
        MyRobot.setCurrentLocation(Point2D(x, y));
        MyRobot.updateShape();
    }
    void rotateLeft(const double& degrees)
    {
        double angle = MyRobot.getCurrentAngle() + degrees;
        if (angle > 360.0) { angle -= 360.0; }
        MyRobot.setCurrentAngle(angle);
        MyRobot.updateShape();
    }
    void rotateRight(const double& degrees)
    {
        double angle = MyRobot.getCurrentAngle() - degrees;
        if (angle < 0.0) { angle += 360.0; }
        MyRobot.setCurrentAngle(angle);
        MyRobot.updateShape();
    }
    void addObstacle(const Point2D& point)      // Empty Function Currently... Depends On Robot Design, Sensors Used, etc...
    {

    }
    void removeObstacle(const Point2D& point)   // Empty Function Currently... Depends On Robot Design, Sensors Used, etc...
    {

    }
    void clearObstacles(void)
    {
        Obstacles.clear();
    }

};

#endif