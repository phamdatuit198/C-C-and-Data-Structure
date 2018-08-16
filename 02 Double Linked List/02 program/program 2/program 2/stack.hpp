//My name: Dat Pham
//class number: CS163
//project number: 2

//Purpose:
/*
 This is a header file of stack including data structure and operation of stack
 */


#include <iostream>
#include "queue.hpp"

//Create arrays of const size MAX
const int MAX = 1;

/*
    Data Structure of n_stack
*/

struct n_stack{
    
    message *data_message;                                      // object message dynamically array
    n_stack *next;                                              // next pointer 
    
};



/*
    Information about data member and operation of stack class
*/

class stack{
    
    public:
        stack();                                                   // Constructor of message
        ~stack();                                                  // Destructor of message
    
        int push(message &_message);                               // push into stack
        int pop();                                                 // remove into stack
        int peek(message &_message);                               // get message from stack and push into argument
        int isEmpty();                                             // check array stack is empty or it is not
        int display();
        int isfull();                                              // check array stack is full or it is not

    private:

        n_stack *head;                                             // head pointer of stack
        int top_index;                                         // top_index of array
};



