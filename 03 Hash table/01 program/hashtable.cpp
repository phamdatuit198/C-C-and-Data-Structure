

#include "hashtable.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



/*
 constructor of product class
 
 */

hashtable::hashtable(){
    int size = 5;
    htable = new item_node*[size];
    for(int i = 0;i<size;i++)
        htable[i] = NULL;
    hash_table_size = size;
    
}



/*
 
 destructor of product class
 */

hashtable::~hashtable(){
    for(int i = 0; i<hash_table_size; i++){
        item_node *entry = htable[i];
        while(entry != NULL){
            item_node *temp = entry;
            entry = entry->next;
            delete temp;
        }
    }
    delete []htable;
}



/*
 @purpose: add newItem into hashtable
 
 @param keyword[]
    array character for keyword of item_node
 @param _newItem
    object newItem
 
 @return 1
    when we add done
 */

int hashtable::insert(char keyword[], newItem _newItem){
    int locationArray = strlen(keyword) % hash_table_size;
    if(htable[locationArray] == NULL){
        htable[locationArray] = new item_node();
        htable[locationArray]->item = _newItem;
        htable[locationArray]->next = NULL;
        htable[locationArray]->keyword = new char[strlen(keyword) +1];
        strcpy(htable[locationArray]->keyword,keyword);
    }else{
        item_node *temp = new item_node();
        temp->keyword = new char[strlen(keyword) +1];
        strcpy(temp->keyword, keyword);
        temp->item = _newItem;
        temp->next = htable[locationArray];
        htable[locationArray] = temp;
    }
    
    return 1;
}




/*
 @purpose: search and show newItem at key into hashtable
 
 @param _keyword[]
    array character for keyword of item_node
 @return 1
    when we found element
 @return 0
    when we can't find anything at key
 */

int hashtable::retrieve(char _keyword[]){
    int locationArray = strlen(_keyword) % hash_table_size;
    bool flgFound = false;
    if(htable[locationArray] == NULL){
        cout<<"\nNo Element to found at key";
        return 0;
    }
    else{
        item_node *temp = new item_node();
        temp = htable[locationArray];
        while(temp != NULL)
        {
            if(strcmp(temp->keyword,_keyword)==0){
                cout<<"\nElement was found at key! \n";
                temp->item.display();
                flgFound = true;
            }
            temp = temp->next;
        }
    }
    if(flgFound == false){
        cout<<"\n No Element to found at key! \n";
        return 0;
    }
    return 1;
}



/*
 @purpose: show all of newItem into hashtable
 
 @return 1
    when we add done
 */

int hashtable::displayAll(){
    for (int i = 0;i < hash_table_size;i++){
        item_node *temp = new item_node();
        temp = htable[i];
        cout<<"\nArray slot: "<<i<<"\n";
        while(temp != NULL){
            temp->item.display();
            temp =temp->next;
        }
    }
    return 1;
};










