/*****************************************************************************
 ** Author: Dat Pham
 ** Week 10
 ** Project 10.b
 ** Date: June 5, 2017
 ** Description: Write a function of store class
 ***************************************************************************/
#include <vector>
#include "Store.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;



/*****************************************************************************
 **
 ** Description: Add product to vector product of store
 ** Param: *p pointer of product
 ** Return: no return
 **
 ****************************************************************************/



void Store::addProduct(Product *p){
    inventory.push_back(p);
}



/*****************************************************************************
 **
 ** Description: Add customer to vector customer of store
 ** Param: *c pointer of customer
 ** Return: no return
 **
 ****************************************************************************/

void Store::addMember(Customer *c){
    members.push_back(c);
}


/*****************************************************************************
 **
 ** Description: get product from id of product
 ** Param: id is a id of product with data type string
 ** Return: Product
 **
 ****************************************************************************/

Product* Store::getProductFromID(std::string id){
    Product *result = NULL;
    
    for(int i=0;i<inventory.size();i++)
        if(inventory[i]->getIdCode()==id)
            result= inventory[i];
    
    return result;
    
}



/*****************************************************************************
 **
 ** Description: get Customer from id of Customer
 ** Param: id is a id of customer with data type string
 ** Return: Customer
 **
 ****************************************************************************/

Customer* Store::getMemberFromID(std::string id){
    Customer *result = NULL;
    
    for(int i=0;i<members.size();i++){
        string a = members[i]->getAccountID();
        if(members[i]->getAccountID()==id)
            result= members[i];
    }
    
    return result;
    
}



/*****************************************************************************
 **
 ** Description: search string of list product
 ** Param: str is a string which need to search
 ** Return: no return
 **
 ****************************************************************************/


void Store::productSearch(std::string str){
    
    size_t found1;
    size_t found2;
    //define array of position product if we found
    
    for(int i=0;i<str.length();i++){
        str[i] = tolower(str[i]);
    }
    
    //found string is title and description product
    for(int i=0;i<inventory.size();i++){
        found1= inventory[i]->getTitle().find(str);
        found2= inventory[i]->getDescription().find(str);
        
        if(found1!=std::string::npos || found2!=std::string::npos){
         
            
            //print title
            cout<<inventory[i]->getTitle()<<endl;
            //print ID code
            cout<<"ID code: "<<inventory[i]->getIdCode()<<endl;
            //print price
            cout<<"price: $"<<inventory[i]->getPrice()<<endl;
            //print description
            cout<<inventory[i]->getDescription()<<endl;
            cout<<"\n\n";
        }
    }
}



/*****************************************************************************
 **
 ** Description: add product to member customer by id of product and id of member
 ** Param: pID is a id of product with data type string
 ** Param: nID is a id of customer with data type string
 ** Return: no return
 **
 ****************************************************************************/

void Store::addProductToMemberCart(std::string pID, std::string mID){
    Product *product = getProductFromID(pID);
    Customer *customer = getMemberFromID(mID);

    if(product!=NULL){
        if(customer!=NULL){
            
            //check product avaiable in store
            if(product->getQuantityAvailable()>0){
                
                customer->addProductToCart(product->getIdCode());
                addMember(customer);
            }else
                cout<<"\nSorry, product #"<<pID<<" is currently out of stock.";
            
        }else
            cout<<"\nMember #"<<mID<<" not found!";
    }else
        cout<<"\nProduct #"<<pID<<" not found!";
}



/*****************************************************************************
 **
 ** Description: check out and print product which customer order and calculate price
 ** Param: nID is a id of customer with data type string
 ** Return: no return
 **
 ****************************************************************************/

void Store::checkOutMember(std::string mID){
    
    Customer *customer = getMemberFromID(mID);
    Product *product;
    vector<string> cusCart;
    double subtotal=0;
    double total=0;
    double ship=0;
    if(customer!=NULL){
        cusCart = customer->getCart();
        //check cart of customer is empty or it is not
        if(!cusCart.empty()){
            for(int i=0;i<cusCart.size();i++){
                //get product order
                product = getProductFromID(cusCart[i]);
                if(product->getQuantityAvailable()>0){
                    cout<<"\n";
                    cout<<product->getTitle()<<" = "<<product->getPrice();
                    product->decreaseQuantity();
                    subtotal =subtotal+product->getPrice();
                }else
                    cout<<"\nSorry, product #"<<cusCart[i]<<","<<product->getTitle()<<", is no longer available.";
            }
            //show subtotal
            cout<<"\nSubtotal: $"<<subtotal;
            
            //show ship
            if(customer->isPremiumMember())
                ship=0;
            else
                ship = (7*subtotal)/100;
            
            total = subtotal+ship;
            cout<<"\nShipping Cost: $"<<ship;
            cout<<"\nTotal: $"<<total;
            cout<<"\n";
            //delete empty cart of customer
            customer->emptyCart();
        }else
            cout<<"\nThere are no items in the cart!";
    }else
        cout<<"\nMember #"<<mID<<" not found!";
}




























