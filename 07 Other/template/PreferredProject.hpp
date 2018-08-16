/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.b
 ** Date: May 22, 2017
 ** Description: Write PreferredProject class inherit from CustomerProject class
 
 ***************************************************************************/

#ifndef PREFERREDPROJECT_HPP
#define PREFERREDPROJECT_HPP

#include <iostream>
#include "CustomerProject.hpp"

class PreferredProject:public CustomerProject{
    
private:
    
    //no data member
    
public:
    PreferredProject(double,double,double);     //constructor
    double billAmount();                        //override billAmount function of customerproject
};


#endif
