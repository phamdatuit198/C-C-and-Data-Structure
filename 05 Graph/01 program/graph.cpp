//My name: Dat Pham
//class number: CS163
//project number: 5
//Purpose:
/*
 we are using table ADT using graph.
 we will develop a function for create, insert, display infor about vertex and list of adjacent
 */


#include "graph.h"
#include <iostream>

using namespace std;



// Myfriend class

//constructor of myfriend

myfriend::myfriend(){
    name = NULL;
    event = NULL;
}



//destructor of myfriend class

myfriend::~myfriend(){
    delete []name;
    delete []event;
}



/*
 @purpose: add information into myfriend object
 
 @param _name[]
 array character for name of myfriend
 
 @param _event[]
 array character for event of myfriend
 
 @return 1
 when we add done
 */

int myfriend::addInfor(char _name[], char _event[]){

    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    
    event = new char[strlen(_event)+1];
    strcpy(event,_event);
    
    return 1;
}




/*
 @purpose: copy information into myfriend object
 
 @param _myfriend
    _myfriend is a object of myfriend class
 
 @return 1
 when we add done
 */

int myfriend::copy(myfriend &_myfriend){
    
    name = new char[strlen(_myfriend.name)+1];
    strcpy(name,_myfriend.name);
    
    event = new char[strlen(_myfriend.event)+1];
    strcpy(event, _myfriend.event);
    return 1;
}




/*
 @purpose: compare two vertex
 
 @param _keyvalue[]
    content of vertex need to compare with current vertex
 
 @return 1
        if two vertex is same
 @return 0
        if two vertex is different
 */


int myfriend::compare(char _keyvalue[]){
    
    if(strcmp(event, _keyvalue)==0)
        return 1;
    else
        return 0;
}




/*
 @purpose: get event of current vertex
 
 @return event
 when we add done
 */

char *myfriend::getevent(){
    return event;
}



/*
 @purpose: get name of current vertex
 
 @return name
 when we add done
 */

char *myfriend::getname(){
    return name;
}



// Table class
// constructor of Table


table::table(int size){
    
    adjacent_list = new vertex[size];
    
    for(int i = 0;i<size;i++){
        adjacent_list[i].head = NULL;
        adjacent_list[i].entry = NULL;
    }
    list_size = size;
}



//destructor of table class

table::~table(){
    
    list_size = 0;
    delete []adjacent_list;
}



/*
 @purpose: add myfriend object into adjacent_list
 
 @param _myfriend
        the object of myfriend class
 
 @return 1
        when we add done
 */


int table::addvertex(myfriend &_myfriend){
   
    for(int i = 0;i<list_size;i++){
        
        if(adjacent_list[i].entry==NULL){
           
            myfriend *temp = new myfriend;
            temp->copy(_myfriend);
            adjacent_list[i].entry = temp;
            
            return 0;
        }
            
    
    }
    
    return 1;
}



/*
 @purpose: find location of current vertex
 
 @return _keyvalue[]
    content of current vertex
 
 @return location of vertex which same current vertex
 
 @return -1 when we don't find any vertex same with current vertex
 
 */

int table::find_location(char _keyvalue[]){
   
    for(int i = 0; i<list_size;i++){
      //  cout<<"\nname: "<<adjacent_list[i].entry->getevent();
        if(adjacent_list[i].entry->compare(_keyvalue) == 1)
            return i;
    }
    return -1;
}




/*
 @purpose: add node into list of adjacent
 
 @param _currentvertex
        vertex current
 @param _to_attach
         vertex need to connect
 @return 1
 when we add done
 */

int table::addedge(char *_currentvertex, char *_to_attach){
    
    int connection1 = find_location(_currentvertex);
    int connection2 = find_location(_to_attach);
    
    
    if(!adjacent_list[connection1].head){
        adjacent_list[connection1].head = new node;
        adjacent_list[connection1].head->adjacent= &adjacent_list[connection2];
        adjacent_list[connection1].head->next = NULL;
    }else{
        node *temp = new node;
        temp->adjacent = &adjacent_list[connection2];
        temp->next = adjacent_list[connection1].head;
        adjacent_list[connection1].head = temp;
    }
    return 1;
}



/*
 @purpose: display graph
 
 @return 1
    when we add done
 */

int table::display(){
    
    for(int i= 0; i<list_size;i++){
    
        cout<<"\nAdjacency list of vertex "<<i<<"\n";
        node *temp = new node;
        temp = adjacent_list[i].head;
        printNode(temp);
        cout<<"\n";
    }
    
    return 1;
}



/*
 @purpose: display node of adjacency list of vertex
 
 @return 1
    when we add done
 @return 0
    when temp is null
 */


int table::printNode(node *temp){
    
    if(!temp)
        return 0;
    else{
        cout<<" ---> ( "<<temp->adjacent->entry->getevent()<<","<<temp->adjacent->entry->getname()<<" )";
        printNode(temp->next);
    }
    return 1;
}






