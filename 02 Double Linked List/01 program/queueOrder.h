//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/* this file contains the information about managing all of order arrived. We need to keep track of order*/

# include <iostream>

class order{
    
    public:
        order();
        ~order();
        bool addOrder(char _namePro[],int _quantity);
        bool display();
    
    private:
        char *namePro;
        int quantity;
};

struct o_node{
    order *nodeOrder; // the array use dynamically allocated
    o_node *next;
    int size_of_array;//size of array
};

class listOrder{ // list order by CLL
    
    public:
        listOrder();
        ~listOrder();
        bool setSizeOfArray(int _size_of_array);
        bool addListOrder(order _order);
        bool checkWareHouse(o_node o_noder_order);
        bool peek();
    
        bool display();
    private:
            o_node *rear;
            int topIndex;
    
            int size_of_order;
            bool flgFull;
 };

struct s_order{
    char *name;
    s_order *next;
};


