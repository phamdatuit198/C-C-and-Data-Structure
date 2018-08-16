//My name: Dat Pham
//class number: CS163
//project number: 3
//Purpose:
/* this file contains the information about newsItem.
    the newsItem has two main function such as addNew and display
 
 */

#include <iostream>



class newItem{

    public:
        newItem();// constructor
        ~newItem();//destructor
    
        int addNew(char _title[], char _comment[],int _coutLike,int _coutView, int _coutComment, char keyWord[]); // add information into object newItem
    
        int display();//display information of newitem
    
    private:
        char *title; // variable is defined title of new item
        char *comment;// variable is defined comment of new item
        int coutLike;// variable is defined quantity like of new item
        int coutView;// variable is defined quantity view of new item
        int coutComment;// variable is defined quantity comment of new item
        char *keyWord;// variable is defined keyword of new item
};

struct item_node{
    char *keyword; //keyword of node
    newItem item;  // object newItem
    item_node *next;//pointer next
};

