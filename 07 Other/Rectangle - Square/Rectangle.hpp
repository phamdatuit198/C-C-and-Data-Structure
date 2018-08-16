/*****************************************************************************
 ** Author: Dat Pham
 ** Week 7
 ** Project 7.a
 ** Date: May 15, 2017
 ** Description: The class define Rectangle with length and width. We have funtion
                    calculate area and perimeter.
 ***************************************************************************/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

//defind function of Rectangle class

class Rectangle{
    
private:
    double length;                  //data member lenth with data type double
    double width;                   //data member width with data type double

public:
    Rectangle(double,double);       //constructor function
    double getLength();             //get length of rectangle function
    double getWidth();              //get width of rectangle function
    void setLength(double);         //set lendth function
    void setWidth(double);          //set width function
    double area();                  //function calculate area of rectangle
    double perimeter();             //function calculate perimeter of rectangle
};
#endif
