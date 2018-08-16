
/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.b
 ** Date: May 22, 2017
 ** Description: Write CustomerProject is base class
 
 ***************************************************************************/


#ifndef CUSTOMERPROJECT_HPP
#define CUSTOMERPROJECT_HPP

#include <iostream>

class CustomerProject{

private:
    double hours;
    double materials;
    double transportation;
public:
    CustomerProject(double,double,double);  //constructor functuon
    void setHours(double);                  //Set hour function
    void setMaterials(double);              //Set materials function
    void setTransportation(double);         //set transportation function
    double getHours();                         //get hour function
    double getMaterials();                     //get material function
    double getTransportation();                //get transportation function
    virtual double billAmount()=0;          //pure function 
};


#endif
