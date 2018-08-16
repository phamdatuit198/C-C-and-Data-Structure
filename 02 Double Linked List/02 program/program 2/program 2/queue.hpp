//My name: Dat Pham
//class number: CS163
//project number: 2

//Purpose:
/*
    This is a header of class queue
*/


#include <iostream>
#include "message.hpp"


/*
    Data Structure of n_message
*/

struct n_message{
    
    message data_message;                               // object message
    n_message *next;                                    // next pointer
    
};


/*
    Information about data member and operation of queue class  
*/

class queue{

    public:
        queue();                                        // Constructor of message
        ~queue();                                       // Destructor of message
    
        int enqueue(message &_message);                 // Insert message into queue
        int dequeue();                                  // remove message from queue
        int peek(message &_message);                    // get message from queue and push into argument
        int isempty();                                  // check queue is empty or it is not
        int display();                                  // display queue
        
    private:
        n_message *rear;                                // pointer of queue this is a tail of list
};

