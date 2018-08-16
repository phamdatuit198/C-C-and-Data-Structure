/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.b
 ** Date: June 5, 2017
 ** Description: Write a function of Customer class
 ***************************************************************************/

#include "Customer.hpp"



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user
 ** Param: initial_name with data type is string
 ** Param: initial_acc with data type is string
 ** Param: pre with data type is boolean
 **
 ****************************************************************************/



Customer::Customer(std::string initial_name,std::string initial_acc,bool pre){
    name = initial_name;
    accountID = initial_acc;
    premiumMember = pre;
}



/*****************************************************************************
 **
 ** Description: get accountID return string data type
 ** return: string
 **
 ****************************************************************************/


std::string Customer::getAccountID(){
    return accountID;
}



/*****************************************************************************
 **
 ** Description: get Cart return vector data type
 ** return: vector of string
 **
 ****************************************************************************/


std::vector<std::string> Customer::getCart(){
    return cart;
}



/*****************************************************************************
 **
 ** Description: add ID of product to Cart
 ** Param: to_add this is a ID of product
 ** return: no return
 **
 ****************************************************************************/


void Customer::addProductToCart(std::string to_add){
    cart.push_back(to_add);
}


/*****************************************************************************
 **
 ** Description: get value of preminumMember return boolean
 ** return: boolean
 **
 ****************************************************************************/


bool Customer::isPremiumMember(){
    return premiumMember;
}



/*****************************************************************************
 **
 ** Description: delete cart of customer
 ** return: no return
 **
 ****************************************************************************/



void Customer::emptyCart(){
    while(!cart.empty()){
        cart.pop_back();
    }
}
