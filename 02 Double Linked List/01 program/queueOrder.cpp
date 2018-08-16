//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/*
 we are using queue of array for managing a list of order because customer can order many products
 we will develop a function for add infor and display
 */

#include "queueOrder.h"
# include "product.h"
using namespace std;


//Constructor of class order

order::order(){
    namePro = NULL;
    quantity = 0;
}



//destructor of class order

order::~order(){
    if(namePro)
        namePro=NULL;
    if(quantity!=0)
        quantity = 0;
}



/*
 @purpose: add information of order into object order
 
 @param name_Pro[]
 array character for name of order
 @param quality
 number order you need to order
 
 @return true
 when we add done
 */

bool order::addOrder(char _namePro[], int _quatity){
    
    namePro = new char[strlen(_namePro) + 1];
    strcpy(namePro, _namePro);

    quantity = _quatity;
    return true;
}



//display information of order such as name and quality

bool order::display(){
    
    cout<<"\nName: "<<namePro;
    cout<<"\nQuality: "<<quantity;
    return true;
}







//Function for list

//Constructor of listOrder class

listOrder::listOrder(){
    rear = NULL;
    topIndex = 0;
    flgFull = false;
}



//destructor of listOrder class

listOrder::~listOrder(){
    o_node *temp = new o_node;
    while(rear->next != rear){
        temp = rear->next;
        rear->next=temp->next;
        delete temp;
    }
    topIndex = 0;
}

/*
 @purpose: set size of order example how many order you need for order.
 
 @return true
 when we add done
 */
bool listOrder::setSizeOfArray(int size){
    size_of_order = size;
    return true;
}



/*
 @purpose: add order into list order
 
 @param _order
    object order
 
 @return true
 when we add done
 */

bool listOrder::addListOrder(order _order){
    
   
    
    if(!rear){
        rear = new o_node;
        rear->next = rear;
        rear->nodeOrder = new order[size_of_order];
        rear->nodeOrder[topIndex++] = _order;
        rear->size_of_array = size_of_order;

    }else{
        if(topIndex!=size_of_order && flgFull == false){
           
             rear->nodeOrder[topIndex++] = _order;
        }else{
            topIndex=0;
            flgFull = false;
            
            o_node *temp = new o_node;
            temp->nodeOrder = new order[size_of_order];
            temp->nodeOrder[topIndex++] = _order;
            temp->size_of_array = size_of_order;
            
            temp->next = rear->next;
            rear->next = temp;
            rear = temp;
        }
    }
    
    if(topIndex == size_of_order){
        
        flgFull = true;
    }
    return true;
    
}



/*
 @pupose: display list of order
 @return true when we done
 */


bool listOrder::display(){

    while(rear->next != rear){
        cout<<"\n###########";
        for(int i=0; i<rear->next->size_of_array;i++){
            rear->next->nodeOrder[i].display();
        }
        rear->next = rear->next->next;
    }
    
    if(rear->next == rear){
        cout<<"\n###########";
        for(int i=0; i<rear->next->size_of_array;i++){
            rear->next->nodeOrder[i].display();
        }
    }
        
    return true;
}

/*
 @pupose: display order information of top queue
 @return true when we done
 */

bool listOrder::peek(){
    cout<<"\n\nTop queue: ";
    for(int i = 0; i<rear->next->size_of_array;i++)
        rear->next->nodeOrder[i].display();
    return true;
}

