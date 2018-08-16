//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/*
 This is a header of class message and list saving and list block of sender
 */


#include <iostream>


/*
    Information about data member and operation of message class
*/

class message{

    public:
        message();                                   // Constructor of message
        ~message();                                  // Destructor of message
        int insert(char _sender[], char _message[]); // Insert information to data member
        int copy(message &_message);                 // copy information of argument into data member
        int checkSender(char _sender[]);             // check Sender NULL or no
        int display();                               // display data member
        int isEmpty();                               // check argument is empty or it is not
    private:
        char *text;                                  // data member text using dynamically allocate array
        char *sender;                                // data member sender using dynamically allocate array
};


/*
    Data Structure of n_block
*/

struct n_block{
    
    char *sender;                                   // Dynamically alocate array sender
    n_block *next;                                  // next pointer
    
};



/*
    Information about data member and operation of listBlock class
*/


class listBlock{
   
    public:
    
        listBlock();                                // Constructor of message
        ~listBlock();                               // Destructor of message
        int insert(char _sender[]);                 // Insert information to data member
        void display();                             // display data member

    private:
        n_block *head;                              // pointer head of list
        n_block *tail;                              // pointer tail of list

};


/*
    Data Structure of n_save
*/

struct n_save{
    
    message data_message;                           // operation message saving
    n_save *next;                                   // next pointer of node
    
};



/*
    Information about data member and operation of listSave class
*/

class listSave{
    
    public:
    
        listSave();                                     // Constructor of message
        ~listSave();                                    // Destructor of message
        int insert(message &_message);                  // Insert information to data member
        void display();                                 // display data member

    private:
        n_save *head;                                   // pointer head of list
        n_save *tail;                                   // pointer tail of list
};



