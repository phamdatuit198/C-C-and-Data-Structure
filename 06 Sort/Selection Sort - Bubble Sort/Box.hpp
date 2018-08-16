/*****************************************************************************
 ** Author: Dat Pham
 ** Week 5
 ** Project 5b
 ** Date: April 29, 2017
 ** Description: The program set methods height, width, and length.
                 Calculate and return the volume of the box and the surface area of the box
 ***************************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

#include <string>
#include <iostream>

//Define the interface of the Box class

class Box{
  
private:
    
    double height;                  //define height variable of box
    double width;                   //define width variable of box
    double length;                  //define length variable of box
    
public:
    
    Box();                          //default constructor 
    Box(double,double,double);      //constructor
    
    void setHeight(double);         //set height variable
    void setWidth(double);          //set width variable
    void setLength(double);         //set length variable
    double calcVolume();            //calculate volume funtion of box
    double calcSurfaceArea();       //calculate total surface area of box
    
};
#endif
