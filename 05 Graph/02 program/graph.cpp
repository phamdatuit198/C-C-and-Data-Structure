//
//  graph.cpp
//  graph
//
//  My name: Dat Pham
//  class number: CS163
//  project number: 5
//  Purpose:
/*
    We will implement some function for table object
 */

#include <iostream>
#include <cstring>
#include "graph.hpp"
using namespace std;


/*
    constructor of Table
*/



table::table(int size){
    list_size = size;
    adjacency_list = new vertex[size];
    for(int i=0; i<size;i++){
        adjacency_list[i].head = NULL;
        adjacency_list[i].entry = NULL;
    }
}



/*
    destructor of table class
*/



table::~table(){
    
    list_size = 0;
    delete []adjacency_list;


}



/*
 
 @purpose: add journal_entry object into vertex
 
 @param to_add
    the object of journal_entry class
 
 @return 1
    when we add done

 */



int table::insert_vertex(journal_entry &to_add){
    
    
    for(int i = 0;i<list_size;i++){
         if(adjacency_list[i].entry==NULL){
             adjacency_list[i].entry = new journal_entry;
             adjacency_list[i].entry->copy_entry(to_add);
             //adjacency_list[i].entry->display();
             i = list_size;
         }
    }
    
    return 1;
}


/*
 
 @purpose: find location of current vertex
 
 @return *key_value
    content of current vertex
 
 @return location of vertex which same current vertex
 
 @return -1 when we don't find any vertex same with current vertex
 
 */



int table::find_location(char *key_value){
    
    for(int i = 0;i<list_size;i++){
        if(adjacency_list[i].entry!=NULL && adjacency_list[i].entry->compare(key_value))
            return i;
    }
    return -1;
}



/*
 
 @purpose: add node into list of adjacent
 
 @param *current_vertex
    vertex current
 
 @param _to_attach
    vertex need to connect
 
 @return 1
    when we add done
 */



int table::insert_edge(char *current_vertex, char *to_attach){
    int locaCurrent = find_location(current_vertex);
    int locaAttach = find_location(to_attach);
    if(locaCurrent == -1 && locaAttach == -1)
        return 0;
    if(!adjacency_list[locaCurrent].head){
        adjacency_list[locaCurrent].head = new node;
        adjacency_list[locaCurrent].head->adjacent= &adjacency_list[locaAttach];
        adjacency_list[locaCurrent].head->next = NULL;
    }else{
        node *temp = adjacency_list[locaCurrent].head;
        adjacency_list[locaCurrent].head = new node;
        adjacency_list[locaCurrent].head->adjacent = &adjacency_list[locaAttach];
        adjacency_list[locaCurrent].head->next = temp;
    }
    return 1;

}



/*
 
 @purpose: display graph
 
 @return 1
    when we add done
 
*/



int table::display_all(){
    
    for(int i = 0; i<list_size;i++){
        node *temp = adjacency_list[i].head;
        cout<<"Vertex "<<adjacency_list[i].entry->getTitle()<<": ";
        while(temp!=NULL){
            cout<<"--> ( "<<temp->adjacent->entry->getTitle()<<":"<<temp->adjacent->entry->getNotes()<<" ) ";
            temp = temp->next;
        }
         cout<<"\n\n";
    }
    
    return 1;
}



/*
 
 @purpose: display vertex
 
 @return 1
    when we add done
 
 */



int table::display_vertex(){
    for(int i = 0;i<list_size;i++){
            adjacency_list[i].entry->display();
    }

    return 1;
}




/*
 
 @purpose: wapper check graph
 
 @return 1
    if graph is complete
 @return 2
    if graph is connected
 
 */




int table::checkGraph(){
    
    int result;
    int num=0;
    
    if(!adjacency_list)
        return 0;
    
    for(int i = 0; i<list_size;i++){
        
            result = checkGraph(adjacency_list[i].head);
            
            if(result<list_size-1)
                return 2;
    }
    return 1;
}


/*

 @purpose: check graph recuriton
 
 @param: head
    pointer of node
 
 @return count
 
*/



int table::checkGraph(node *&head){
    
    int count=0;
    
    if(!head)
        return 0;
    
    count = checkGraph(head->next)+1;
    
    return count;
}










