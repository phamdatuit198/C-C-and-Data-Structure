/*****************************************************************************
 ** Author: Dat Pham
 ** Week 7
 ** Project 7.b
 ** Date: May 15, 2017
 ** Description: The class define MyInteger.
 
 ***************************************************************************/

#include "MyInteger.hpp"

/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user.
 ** Param: value with data type is int
 **
 ****************************************************************************/

MyInteger::MyInteger(int value){
    pInteger = new int;
    *pInteger = value;
}



/*****************************************************************************
 **
 ** Description: Destructor function delete memory of data member
 **
 ****************************************************************************/


MyInteger::~MyInteger(){
    
    if(pInteger)
        delete pInteger;
}



/*****************************************************************************
 **
 ** Description: copy constructor, copy two object together
 ** Param: to_copy with data type is MyInteger
 **
 ****************************************************************************/

MyInteger::MyInteger(const MyInteger &to_copy){
    pInteger = new int;
    setMyInt(*to_copy.pInteger);
}



/*****************************************************************************
 **
 ** Description: return value of data member
 ** Param: data type is int
 **
 ****************************************************************************/

int MyInteger::getMyInt(){
    return *pInteger;
}



/*****************************************************************************
 **
 ** Description: set value for data member
 ** Param: to_copy with data type is MyInteger
 **
 ****************************************************************************/

void MyInteger::setMyInt(int value){
    *pInteger = value;
}




/*****************************************************************************
 **
 ** Description: overloading operator "=" for copy data two object
 ** Param: to_copy with data type is MyInteger
 ** Return: MyInteger
 ****************************************************************************/

MyInteger MyInteger::operator=(const MyInteger &to_copy){
    pInteger = new int();
    setMyInt(*to_copy.pInteger);
    return *this;
}


