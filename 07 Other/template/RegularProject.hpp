/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.b
 ** Date: May 22, 2017
 ** Description: Write RegularProject class inherit from CustomerProject class
 
 ***************************************************************************/
#ifndef REGULARPROJECT_HPP
#define REGULARPROJECT_HPP

#include <iostream>
#include "CustomerProject.hpp"

class RegularProject:public CustomerProject{

private:
    
    //no data member
    
public:
    RegularProject(double,double,double);   //constructor
    double billAmount();                    //override billAmount function of customerproject

};

#endif
