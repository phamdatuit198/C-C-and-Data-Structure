/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.b
 ** Date: June 5, 2017
 ** Description: Write a function of Product class
 ***************************************************************************/

#include "Product.hpp"



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user
 ** Param: initial_id with data type is string
 ** Param: initial_title with data type is string
 ** Param: initial_dis with data type is string
 ** Param: pri with data type is double
 ** Param: qua with data type is int
 **
 ****************************************************************************/



Product::Product(std::string initial_id,std::string initial_title,std::string initial_dis,double pri,int qua){
    
    idCode = initial_id;
    title  = initial_title;
    description = initial_dis;
    price   = pri;
    quantityAvailable = qua;
}

/*****************************************************************************
 **
 ** Description: get IdCode return string data type
 ** return: string
 **
 ****************************************************************************/

std::string Product::getIdCode(){
    return idCode;
}



/*****************************************************************************
 **
 ** Description: get title of product and return string data type
 ** return: string
 **
 ****************************************************************************/

std::string Product::getTitle(){
    return title;
}



/*****************************************************************************
 **
 ** Description: get description of product and return string data type
 ** return: string
 **
 ****************************************************************************/

std::string Product::getDescription(){
    return description;
}



/*****************************************************************************
 **
 ** Description: get price of product and return double data type
 ** return: double
 **
 ****************************************************************************/

double Product::getPrice(){
    return price;
}



/*****************************************************************************
 **
 ** Description: get quatity of product and return int data type
 ** return: int
 **
 ****************************************************************************/

int Product::getQuantityAvailable(){
    return quantityAvailable;
}



/*****************************************************************************
 **
 ** Description: decrease 1 amount of quatityAquailable
 ** return: no return
 **
 ****************************************************************************/

void Product::decreaseQuantity(){
    quantityAvailable--;
}
