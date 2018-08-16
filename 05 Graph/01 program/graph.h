//My name: Dat Pham
//class number: CS163
//project number: 5
//Purpose:
/*
 this file contains the information for graph and managing
 a list of the advantage and disadavantage. we will create, insert, display for graph.
 
 */

#include <iostream>

/*
 Create a myfriend class  with
 information about variable and function of myfriend
 */

class myfriend{
    
    public:
    
        myfriend();
        ~myfriend();
        int addInfor(char name[], char event[]);
        char *getname();
        char *getevent();
        int copy(myfriend &_myfriend);
        int compare(char keyvalue[]);
        int display();
    
    private:
    
        char *name;
        char *event;

};



// define vertex
// for each node has *entry, *head

struct vertex{
    
    myfriend *entry;
    struct node *head;
};



// define node
// for each node has adjacent, *next

struct node{
    
    vertex *adjacent;
    node *next;
};



/*
 Create a table class with
 information about variable and function of table
 */

class table{

    public:
    
        table(int size);
        ~table();
        int setListSize(int size);
        int addvertex(myfriend &_myfriend);
        int find_location(char keyvalue[]);
        int addedge(char *current_vertex, char *to_attach );
        int display();
        int printNode(node *node);
   
    private:
    
        vertex *adjacent_list;
        int list_size;
};


