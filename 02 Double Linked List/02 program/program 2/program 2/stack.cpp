//My name: Dat Pham
//class number: CS163
//project number: 2

//Purpose:
/*
 This is a file to implement operation of class stack 
 */


#include "stack.hpp"


/*
    Constructor of message
*/

stack::stack(){
    head = NULL;
    top_index = 0;
}


/*
    Destructor of message
*/

stack::~stack(){
    
    if(head){
        while(head!=NULL){
            n_stack *temp = head;
            head = head->next;
            delete temp;
        }
        top_index = 0;
    }
}


/*
 
 @purpose: add message into stack
 
 @param _message
    object of message class
 @return:
    0 when argument is NULL
    1 when we insert done
*/


int stack::push(message &_message){
    
    //check argument is NULL or it's not
    
    if(_message.isEmpty()==0)
        return 0;
    if(!head)
    {
        head = new n_stack;
        head->data_message = new message[MAX+1];
       // head->data_message[top_index].copy(_message);
       (*(head->data_message + top_index)).copy(_message);
        head->next = NULL;
    }else{
        //check array full or it is not
        if(isfull()==0){
            top_index++;
            //head->data_message[top_index].copy(_message);
            (*(head->data_message + top_index)).copy(_message);
        }else{
            top_index = 0;
            n_stack *temp = new n_stack;
            temp->data_message = new message[MAX+1];
           // temp->data_message[top_index].copy(_message);
            (*(temp->data_message + top_index)).copy(_message);
            temp->next = head;
            head = temp;
        }
    
    }
    return 1;
}


/*
 
 @purpose: remove message from stack
 
 
 @return:
    0 when stack empty
    1 when we remove done
 */


int stack::pop(){
    
    //stack is empty or it's not
    
    if(!head)
        return 0;
    //remove element of array first

    top_index = top_index -1;
    
       if(isEmpty() == 1){
        //destroy head
        n_stack * temp = head;
        head= head->next;
        delete temp;
        top_index = MAX;
    }
    return 1;
}



/*
 
 @purpose: remove message from stack at top
 
 
 @return:
    0 when queue empty
    1 when we remove done
 */


int stack::peek(message &_message){
    
    //check stack is empty or it's not
    
    if(!head)
        return 0;
    
   // _message.copy(head->data_message[top_index]);
    _message.copy(*(head->data_message + top_index));
    return 1;
}


/*
 
 @purpose: check array of stack is empty or its not
 
 
 @return:
    0 when array stack is not empty
    1 when array of stack is empty
 */

int stack::isEmpty(){
    
    if(top_index < 0)
        return 1;
    else
        return 0;
}



/*
 
 @purpose: check array of stack is full or it's not
 
 
 @return:
    0 when array stack is not full
    1 when array of stack is full
 */

int stack::isfull(){

    if(top_index == MAX)
        return 1;
    else
        return 0;
}



/*
 
 @purpose: display information of stack
 
 @return
    0: if stack is NULL
    1: when we are be done
 */


int stack::display(){
    
    //check stack is null or it's not
    
    if(!head)
        return 0;
    
    n_stack *temp = head;
    int top = top_index;
    
    while(temp!=NULL){
        for(int i = top;i>=0; i--)
          //  temp->data_message[i].display();
            (*(temp->data_message + i)).display();
        temp = temp->next;
        top= MAX;
    }
    return 1;
}




