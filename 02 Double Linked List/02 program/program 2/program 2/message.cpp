//My name: Dat Pham
//class number: CS163
//project number: 2

//Purpose:
/*
 This is a file to implement operation of class message and list saving and list block of sender
 */

#include  <cstring>
#include  <iostream>
#include "message.hpp"

using namespace::std;


/* 
    Constructor of message
*/


message::message(){
    sender = NULL;
    text = NULL;
}


/*
    Destructor of message
*/

message::~message(){
    
    if(sender)
        delete [] sender;
    
    if(text)
        delete [] text;

    
}

/*
 
 @purpose: add information for message
 
 @param _message
    object of message class
 @return:
    0 when argument is NULL
    1 when we insert done
 
*/

int message::insert(char _sender[], char _message[]){
    
    //check argument has NULL or they aren't
    if(_sender == NULL || _message == NULL)
        return 0;
    else{
        //copy argument into the data member
        
        //create a variable and deep copy
        if(sender)
            delete [] sender;
        
        sender = new char[strlen(_sender)+1];
        strcpy(sender, _sender);
        
        if(text)
            delete [] text;
        
        text = new char[strlen(_message)+1];
        strcpy(text,_message);
        
        return 1;
    }
}



/*
 
 @purpose: copy from object message to another object message
 
 @param _message
    object message class
 @return:
        0: if _message is NULL
        1: when we insert done
 
 */


int message::copy(message &_message){
    
    //check argument has NULL or no
    
    if(_message.isEmpty()==0)
        return 0;
    else{
        insert(_message.sender,_message.text);
        return 1;
    }
}



/*
 
 @purpose: check message is NULL of it is not
 
 @return
    0: if data member is NULL
    1: when we are be done
 */


int message::isEmpty(){
    
    //check data member of argument has NULL or no
    
    if(sender == NULL || text == NULL)
        return 0;
    else
        return 1;
    
}


/*
 
 @purpose: check sender is same with data member or it is not
 
 @return
        0: if sender is NULL
        1: when we are be done
 */


int message::checkSender(char _sender[]){

    if(_sender == NULL)
        return 0;
    else{
        //check argument with data member
        if(strcmp(sender,_sender)==0)
            return 1;
        else
            return 0;
    }
}



/*
 
 @purpose: display information for message
 
 @return 
        0: if data member is NULL
        1: when we are be done
*/


int message::display(){
    
    //check data member of argument has NULL or no
    
    if(sender==NULL || text == NULL)
        return 0;
    else{
        cout<<"\n";
        cout<<"\n Sender: "<<sender;
        cout<<"\n Text: "<<text;
        return 1;
    }
}




//****LIST BLOCK SENDER CLASS*****

/*
    constructor of listBlock class
*/

listBlock::listBlock(){
    head = NULL;
    tail = NULL;
}



/*
    destructor of listBlock class
 */

listBlock::~listBlock(){
    n_block *temp = new n_block;
    
    while(head!=NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    
    
}



/*
 
 @purpose: add name of sender which need to block into listBlock
 
 @param _sender
        array of character
 @return:
        0 when argument is NULL
        1 when we insert done
 
 */

int listBlock::insert(char _sender[]){
    
    //check _message is NULL or it is not
    
    if(_sender==NULL)
        return 0;
    else{
        if(!head){
            head = new n_block;
            head->sender = new char[strlen(_sender)+1];
            strcpy(head->sender, _sender);
            head->next = NULL;
            
            tail=head;
        }else{
            n_block *temp = new n_block;
            temp->sender = new char[strlen(_sender)+1];
            strcpy(temp->sender,_sender);
            temp->next = NULL;
            
            tail->next = temp;
            tail = temp;
            
        }
        return 1;
    }
}




/*
 
 @purpose: display information for single listBlock
 
 @return nothing
 
 */

void listBlock::display(){
    
    n_block *temp = new n_block;
    temp = head;
    
    while(temp != NULL){
        cout<<"\nsender: "<<temp->sender;
        temp = temp->next;
    }
}




//****LIST MESSAGE SAVE CLASS*****

/*
 
 constructor of listSave class
 
 */

listSave::listSave(){
    head = NULL;
    tail = NULL;
}



/*
    destructor of listSave class
 */

listSave::~listSave(){
    n_save *temp = new n_save;
    
    while(head!=NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    
    
}



/*
 
 @purpose: add message which need to save into listsave
 
 @param _message
        object of message class
 @return:
        0 when argument is NULL
        1 when we insert done
 
 */

int listSave::insert(message &_message){
    
    //check _message is NULL or it is not
    
    if(_message.isEmpty()==0)
        return 0;
    else{
        if(!head){
            head = new n_save;
            head->data_message.copy(_message);
            head->next = NULL;
            
            tail=head;
        }else{
            n_save *temp = new n_save;
            temp->data_message.copy(_message);
            temp->next = NULL;
            
            tail->next = temp;
            tail = temp;
            
        }
        return 1;
    }
}




/*
 
 @purpose: display information for single listSave
 
 @return nothing
 
 */

void listSave::display(){
    
    n_save *temp = new n_save;
    temp = head;
    
    while(temp != NULL){
        temp->data_message.display();
        temp = temp->next;
    }
}


