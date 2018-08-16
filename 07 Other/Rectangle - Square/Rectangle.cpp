/*****************************************************************************
 ** Author: Dat Pham
 ** Week 7
 ** Project 7.b
 ** Date: May 16, 2017
 ** Description: The class define Rectangle with length and width. We have funtion
                    calculate area and perimeter.
 ***************************************************************************/

#include "Rectangle.hpp"



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user
 ** Param: initial_length with data type is double
 ** Param: initial_width with data type is double
 **
 ****************************************************************************/


Rectangle::Rectangle(double initial_length, double initial_width){
    setLength(initial_length);
    setWidth(initial_width);
}



/*****************************************************************************
 **
 ** Description: set length and push data member length with parameter
 **
 ****************************************************************************/



void Rectangle::setLength(double initial_length){
    length = initial_length;
}



/*****************************************************************************
 **
 ** Description: set width and push data member width with parameter
 **
 ****************************************************************************/



void Rectangle::setWidth(double initial_width){
    width   = initial_width;
}



/*****************************************************************************
 **
 ** Description: get length and return length variable
 ** return: double
 **
 ****************************************************************************/


double Rectangle::getLength(){
    return length;
}



/*****************************************************************************
 **
 ** Description: get width and return width variable
 ** return: double
 **
 ****************************************************************************/

double Rectangle::getWidth(){
    return width;
}



/*****************************************************************************
 **
 ** Description: calculate area of Rectangle
 ** return: double
 **
 ****************************************************************************/

double Rectangle::area(){
    return length*width;
}


/*****************************************************************************
 **
 ** Description: calculate perimeter of Rectangle
 ** return: double
 **
 ****************************************************************************/

double Rectangle::perimeter(){
    return (length+width)*2;
}



