//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/*
 we are using stack of array for managing a list of order waiting because customer can order many products waiting
 we will develop a function for add infor and display
 */


#include "stackOrder.h"


using namespace std;


//constructor of orderWaiting class

orderWaiting::orderWaiting(){
    namePro = NULL;
    quantity = 0;
}



//destructor of orderWaiting class

orderWaiting::~orderWaiting(){
    if(namePro)
        namePro=NULL;
    if(quantity!=0)
        quantity = 0;
}



/*
 @purpose: add information of order into object order waiting
 
 @param name_Pro[]
 array character for name of order
 @param quality
 number order you need to order
 
 @return true
 when we add done
 */

bool orderWaiting::addOrderWaiting(char _namePro[], int _quatity){
    
    namePro = new char[strlen(_namePro) + 1];
    strcpy(namePro, _namePro);
    
    quantity = _quatity;
    return true;
}



/*display information of order such as name and quality
   return false if namePro don't have
   return true if namPro have
*/
bool orderWaiting::display(){
    if(!namePro)
        return false;
    else{
        cout<<"\nName: "<<namePro;
        cout<<"\nQuality: "<<quantity;
    }
    return true;
}



//Constructor of listOrderWaiting class

listOrderWaiting::listOrderWaiting(){
    head = NULL;
    topIndex = 0;
}


//destructor of listOrder class
listOrderWaiting::~listOrderWaiting(){
    w_node *temp = new w_node;
    
    while(head!=NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    topIndex = 0;
}


/*
 @purpose: set size of order example how many order you need for order.
 
 @return true
 when we add done
 */
bool listOrderWaiting::setSizeOfArray(int size){
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

bool listOrderWaiting::addListOrderWaiting(orderWaiting _order,bool _checkMoveStack){
    bool checkMoveStack = _checkMoveStack;
    
    if(!head){
        head = new w_node;
        head->next = NULL;
        head->nodeOrder = new orderWaiting[size_of_order];
        head->nodeOrder[topIndex++] = _order;
        head->size_of_array = size_of_order;

        
    }else{
        if(checkMoveStack == false){
            //fill array stack
            head->nodeOrder[topIndex++] = _order;
        }else{
            topIndex=0;
            
            w_node *temp = new w_node;
            temp->nodeOrder = new orderWaiting[size_of_order];
            temp->nodeOrder[topIndex++] = _order;
            temp->size_of_array = size_of_order;
            temp->next = head;
            head = temp;
        }
    }
    
    
    return true;
    
}



/*
 @pupose: display list of order
 @return true when we done
 */

bool listOrderWaiting::display(){
    
    w_node *temp = new w_node;
    temp = head;
    cout<<"\nWAITING ORDER DISPLAY: \n";
    if(!head)
        cout<<"\nDon't have any waiting!\n";
    while (temp!=NULL){
        cout<<"\n########\n";
        for(int i = 0; i<temp->size_of_array;i++)
            temp->nodeOrder[i].display();
        temp = temp->next;
    }
    
    
    return true;
}

/*
 @pupose: display order information of top stack
 @return true when we done
 */

bool listOrderWaiting::peek(){
    cout<<"\n\nWaiting on top: ";

    for(int i = 0; i<head->size_of_array;i++)
        head->nodeOrder[i].display();
    return true;
}

