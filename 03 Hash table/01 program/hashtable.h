
//My name: Dat Pham
//class number: CS163
//project number: 3
//Purpose:
/* this file contains the information about hashtable.
    the hashtable has three main function such as displayAll function, insert function and retrieve function.
 */

#include <iostream>
#include "newsItem.h"

using namespace std;
/*
  information about variable and function of hashtable
 */
class hashtable{
    public:
        hashtable(); //constructor of hashtable
        ~hashtable();//destructor of hashtable
        int retrieve(char _keyword[]);//show all newitem with keyword
        int insert(char _keyword[], newItem _newItem);//insert into hashtable new item
        int displayAll();//display all of them new item
    
    private:
        item_node **htable;   // hashtable variable
        int hash_table_size; // size of hashtable
};