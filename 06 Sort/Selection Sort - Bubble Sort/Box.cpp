/*****************************************************************************
 ** Author: Dat Pham
 ** Week 5
 ** Project 5b
 ** Date: April 29, 2017
 ** Description: The program set methods height, width, and length. 
                  Calculate and return the volume of the box and the surface area of the box
 ***************************************************************************/

#include "Box.hpp"



/*****************************************************************************
 **
 ** Description: Default Constructor set up default value for variable
 **
 ****************************************************************************/



Box::Box(){
    
    setWidth(1);
    setHeight(1);
    setLength(1);
}



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user
 ** Param: initialHeight with data type is double
 ** Param: initialWight with data type is double
 ** Param: initialLength with data type is 
 **
 ****************************************************************************/



Box::Box(double initialHeight, double initialWidth,double initialLength){
    
    setWidth(initialWidth);
    setHeight(initialHeight);
    setLength(initialLength);
}



/*****************************************************************************
 **
 ** Description: set width variable with value from user
 ** param:  setValue with data type double
 ** return: void
 **
 ****************************************************************************/



void Box::setWidth(double setValue){
    width = setValue;
}



/*****************************************************************************
 **
 ** Description: set height variable with value from user
 ** param:  setValue with data type double
 ** return: void
 **
 ****************************************************************************/



void Box:: setHeight(double setValue){
    height = setValue;
}



/*****************************************************************************
 **
 ** Description: set length variable with value from user
 ** param:  setValue with data type double
 ** return: void
 **
 ****************************************************************************/



void Box::setLength(double setValue){
    length = setValue;
}



/*****************************************************************************
 **
 ** Description: Calculator volume of box
 ** return: volume with data type double
 **
 ****************************************************************************/


double Box::calcVolume(){
    
    double volume = 0;
    volume = height * width * length;
    return volume;
}



/*****************************************************************************
 **
 ** Description: Calculator total surface area of box
 ** return: totalArea with data type double
 **
 ****************************************************************************/


double Box::calcSurfaceArea(){
    
    double areaHW;
    double areaHL;
    double areaWL;
    double totalArea;
    
    areaHW = height * width;
    areaHL = height * length;
    areaWL = width * length;
    
    totalArea = 2*areaHW + 2*areaHL + 2*areaWL;
    
    return totalArea;
}



