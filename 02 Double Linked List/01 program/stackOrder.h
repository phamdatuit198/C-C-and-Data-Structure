//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/* this file contains the information about managing orderWaiting. 
   We need to keep track of order Waiting*/

# include <iostream>

class orderWaiting{
    
public:
    orderWaiting();
    ~orderWaiting();
    bool addOrderWaiting(char _namePro[],int _quantity);
    bool display();
    
private:
    char *namePro;
    int quantity;
};

struct w_node{
    orderWaiting *nodeOrder;
    w_node *next;
    int size_of_array;
};

class listOrderWaiting{ // list order by CLL
    
public:
    listOrderWaiting();
    ~listOrderWaiting();
    bool setSizeOfArray(int _size_of_array);
    bool addListOrderWaiting(orderWaiting _order,bool _checkMoveStack);
    bool peek();
    bool display();
private:
    w_node *head;
    int topIndex;
    
    int size_of_order;
    
};

