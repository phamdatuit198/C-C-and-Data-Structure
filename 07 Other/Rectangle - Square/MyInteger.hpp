/*****************************************************************************
 ** Author: Dat Pham
 ** Week 7
 ** Project 7.b
 ** Date: May 15, 2017
 ** Description: The class define MyInteger.

 ***************************************************************************/

#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

#include <iostream>

class MyInteger{

private:
    int *pInteger;                                  //data member
    
public:
    MyInteger(int);                                 //constructor function
    ~MyInteger();                                   //destructor function
    MyInteger(const MyInteger &to_copy);            //copy constructor function
    void setMyInt(int);                             //set value function for data member
    int getMyInt();                                 //get value of data member
    MyInteger operator = (const MyInteger &to_copy);     //overloaded operator functions
};
#endif
