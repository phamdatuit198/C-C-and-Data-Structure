/*****************************************************************************
 ** Author: Dat Pham
 ** Week 7
 ** Project 7.a
 ** Date: May 15, 2017
 ** Description: The class define Square. We have funtion
 calculate area and perimeter.
 ***************************************************************************/


#include "Square.hpp"



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user. We will call
 **                 base class constructor
 ** Param: initial with data type is double
 **
 ****************************************************************************/


Square::Square(double initial):Rectangle(initial,initial){};



/*****************************************************************************
 **
 ** Description: override setlength and push data member width with parameter
 **
 ****************************************************************************/


void Square::setLength(double value){
    Rectangle::setLength(value);
    Rectangle::setWidth(value);
}



/*****************************************************************************
 **
 ** Description: override setwidth function by call baseclass function
 **
 ****************************************************************************/


void Square::setWidth(double value){
    Rectangle::setWidth(value);
    Rectangle::setLength(value);
}
