/*****************************************************************************
 ** Author: Dat Pham
 ** Week 7
 ** Project 7.a
 ** Date: May 15, 2017
 ** Description: The class define Square. We have funtion
                    calculate area and perimeter.
 ***************************************************************************/


#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include "Rectangle.hpp"

//defind function of Square class

class Square : public Rectangle{
    
public:
    Square(double);                 //Constructor of Square class
    void setLength(double);         //Override setLength
    void setWidth(double);          //Override setWidth
};

#endif
