// William Jeremy James

#include "CompetitionField.h"
#include "FireRegion.h"
#include "Point2D.h"
#include "TargetArea.h"
#include <iostream>
#include <vector>

int main()
{   
    CompetitionField Field;

    /*
    int index1 = 0;
    for (FireRegion region : Field.getPotentialFireRegions())
    {
        std::cout << "Potential Fire Region " << index1++ << " Shape\n---------------------\n";
        for (Point2D point : region.getShape())
        {
            std::cout << point.getX() << "," << point.getY() << std::endl;
        }
        std::cout << std::endl;
    }
    */
    
    /*
    int index2 = 0;
    for (TargetArea area : Field.getPotentialTargetAreas())
    {
        std::cout << "Potential Target Area " << index2++ << " Shape\n---------------------\n";
        for (Point2D point : area.getShape())
        {
            std::cout << point.getX() << "," << point.getY() << std::endl;
        }
        std::cout << std::endl;
    }
    */

    /*
    std::cout << "MyRobot Current Location\n------------------------\n";
    std::cout << Field.getMyRobot().getCurrentLocation().getX() << "," << Field.getMyRobot().getCurrentLocation().getY() << "\n\n";
    */

    /*
    std::cout << "MyRobot Shape\n-------------\n";
    for (Point2D point : Field.getMyRobot().getShape())
    {
        std::cout << point.getX() << "," << point.getY() << std::endl;
    }
    std::cout << std::endl;
    */

    //std::cout << "Check If Inside Region/Area: " << Field.checkIfInside() << "\n\n";

    /*
    std::cout << "Angles To Center Of Fire Regions\n--------------------------------\n";
    for (FireRegion region : Field.getPotentialFireRegions())
    {
        std::cout << Field.getAngleTo(region.getCenterPoint()) << std::endl;
    }
    std::cout << std::endl;
    */

    /*
    std::cout << "Distances To Center Of Fire Regions\n-----------------------------------\n";
    for (FireRegion region : Field.getPotentialFireRegions())
    {
        std::cout << Field.getDistanceTo(region.getCenterPoint()) << std::endl;
    }
    std::cout << std::endl;
    */
   
    /*
    Field.moveForwards(60.0);
    std::cout << "MyRobot Shape\n-------------\n";
    for (Point2D point : Field.getMyRobot().getShape())
    {
        std::cout << point.getX() << "," << point.getY() << std::endl;
    }
    std::cout << std::endl;
    */

    /*
    Field.rotateLeft(45.0);
    std::cout << "MyRobot Shape\n-------------\n";
    for (Point2D point : Field.getMyRobot().getShape())
    {
        std::cout << point.getX() << "," << point.getY() << std::endl;
    }
    std::cout << std::endl;
    */

    // Exit Program   
    return 0;
}