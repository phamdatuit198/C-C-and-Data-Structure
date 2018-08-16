//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/* this file contains the information about product. 
    Then, show a list of product in warehouse*/


#include <iostream>
#include <cctype>

/*
 information about product in warehouse
 */
class product{
    
public:
    product();
    ~product();
    bool addNew(char _barcode[], char _name[], char _description[], char _manufacturer[], int _quantity);
    bool checkItem(char _name[]);
    bool display();
private:
    char *description;
    char *barcode;
    char *namePro;
    int quantity;
    char *manufacturer;
};

struct p_node{
    product productInfor;
    p_node *next;
    p_node *prev;
};

/*
 list of product in warehouse
 */
class listProduct{
    
public:
    listProduct();
    ~listProduct();
    bool addNew(product _product);
    bool checkItem(char _name[]);
    bool display();
private:
    p_node *head;
};