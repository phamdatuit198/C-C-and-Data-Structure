//My name: Dat Pham
//class number: CS163
//project number: 1
//Purpose:
/*
 we are using ADT for managing a list of product.
 we will develop a function for update infor and display
 */


#include "product.h"

using namespace std;
/*
 //constructor of product class

 */
product::product(){
    barcode = NULL;
    namePro = NULL;
    description = NULL;
    manufacturer = NULL;
    quantity = 0;

}



/*
 
 destructor of product class
*/

product::~product(){
    if(barcode)
        barcode=NULL;
    if(namePro)
        namePro=NULL;
    if(description)
        description=NULL;
    if(manufacturer)
        manufacturer=0;
    if(quantity!=0)
        quantity =0;
}


/*
 @purpose: add information of product into object product
 
 @param _barcode[]
 array character for barcode of product
 @param _name[]
 array character for  name  of product
 @param _description[]
 array character for _description about product
 @param _manufacturer[]
 array character for manu facturer about product
 @param _quantity
 number quantity in warehouse
 @return true
 when we add done
 */

bool product::addNew(char _barcode[], char _name[], char _description[], char _manufacturer[], int _quantity){
    barcode = new char[strlen(_barcode) + 1];
    namePro = new char[strlen(_name)+1];
    description = new char[strlen(_description)+1];
    manufacturer = new char[strlen(_manufacturer) + 1];
    
    strcpy(barcode, _barcode);
    strcpy(namePro, _name);
    strcpy(description,_description);
    strcpy(manufacturer, _manufacturer);
    quantity = _quantity;
    
    return true;
}


/*
 @purpose: display information for single product
 
 @return true
 when we add done
 */


bool product::display(){
    
    cout<<"\nBarcode: "<<barcode;
    cout<<"\nName of produce: "<<namePro;
    cout<<"\nDescription: "<<description;
    cout<<"\nManufacturer: "<<manufacturer;
    cout<<"\nQuantity: "<<quantity;
    
    return true;
}



/*
 @purpose: check item information about product
 
 @return true when we can find something same
        flase when nothing same in warehouse

 */

bool product::checkItem(char _name[]){
    //cout<<"\nnamePro"<<namePro;
    if(strcmp(namePro, _name) == 0)
        return true;
    else
        return false;
}



/*
    FUNCTION OF LIST PRODUCT
 */
/*
 //constructor of listProduct class
 */
listProduct::listProduct(){
    head=NULL;
}



//destructor of listProduct class


listProduct::~listProduct(){
    p_node *temp = new p_node;
    
        while(head!=NULL){
            temp = head;
            head = head->next;
            delete temp;
        }

}



/*
 @purpose: add information of product into object product
 
 @param _product
 add new product in the list product
 @return true
 when we add done
 */

bool listProduct::addNew(product _product){
    
    if(!head){
        head = new p_node;
        head->productInfor = _product;
        head->next=NULL;
        head->prev=NULL;
    }else{ // have head node before
        p_node *temp= new p_node;
        temp->productInfor = _product;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
    return true;
}



/*
 @purpose: check item information about product
 
 @return true when we can find something same
 flase when nothing same in warehouse
 
 */


bool listProduct::checkItem(char _name[]){
    p_node *temp = new p_node;
    temp = head;
    bool re= false;
    while(temp!= NULL){
      re= temp->productInfor.checkItem(_name);
        if(re == true)
            return re;
        temp = temp->next;
    }
    return re;
}



/*
    show list of product
 */

bool listProduct::display(){
    p_node *temp = new p_node;
    temp = head;
    while(temp!=NULL){
        cout<<"\n LIST OF PRODUCT \n";
        temp->productInfor.display();
        temp = temp->next;
    }
    return true;
}









