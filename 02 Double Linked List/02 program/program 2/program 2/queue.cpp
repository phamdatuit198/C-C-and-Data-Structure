//My name: Dat Pham
//class number: CS163
//project number: 2

//Purpose:
/*
 This is a file to implement operation of class queue
 */

#include "queue.hpp"


/*
    Constructor of message
*/

queue::queue(){
    rear = NULL;
}



/*
    Destructor of message
*/

queue::~queue(){
    n_message *current, *temp;
    if(rear)
    {
        if(rear->next == rear){
            delete rear;
            //rear = NULL;
        }else{
            current = rear->next;
    
            while(current!=rear){
                temp = current;
                current = current->next;
                delete temp;
            }
    
            delete current;
           // rear = NULL;
        }
    }
}



/*
 
    @purpose: add message into queue
 
    @param _message
        object of message class
    @return:
        0 when argument is NULL
        1 when we insert done
*/


int queue::enqueue(message &_message){
    
    //check argument is NULL or it isn't
    
    if(_message.isEmpty()==0)
        return 0;
    else{
        if(!rear){
            rear = new n_message;
            rear->data_message.copy(_message);
            rear->next = rear;
        }else{
            n_message *temp = new n_message;
            temp->data_message.copy(_message);
            temp->next = rear->next;
            
            rear->next = temp;
            rear = temp;
        }
        return 1;
    }
    
}



/*
 
 @purpose: remove message from queue
 
 
 @return:
    0 when queue empty
    1 when we remove done
 */


int queue::dequeue(){
    
    //list is empty
    
    if(!rear)
        return 0;
    else{
        n_message *temp = rear->next;
        
        if(temp->next == rear){
            delete temp;
            rear = NULL;
        }else{
            rear->next = temp->next;
            delete temp;
        }
        return 1;
    }
}


/*
 
 @purpose: remove message from queue at top
 
 
 @return:
    0 when queue empty
    1 when we remove done
 */


int queue::peek(message &_message){
    
    //list is empty
    int result = 0;
    
    if(!rear)
        return 0;
    else{
        result = _message.copy(rear->next->data_message);
        if(result == 0)
            return 0;
        else
            return 1;
    }

}



/*
 
 @purpose: display information for queue
 
 @return
    0: if data member is NULL
    1: when we are be done
 */


int queue::display(){
    
    //check rear is NULL or it isn't
    if(!rear)
        return 0;
    n_message *temp = rear->next;
    do{
        temp->data_message.display();
        temp = temp->next;
    
    }while(temp!=rear->next);
    
    return 1;
    
}




