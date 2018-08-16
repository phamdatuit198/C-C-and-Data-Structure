//
//  graph.hpp
//  graph
//
//  My name: Dat Pham
//  class number: CS163
//  project number: 5
//  Purpose:
/*
    Define some function for journal_entry class
 */


#include "journal_entry.hpp"



/*
    Structure of vertex
*/



struct vertex
{
    
    journal_entry * entry;        //variable entry of journal_entry
    struct node * head;           //variable head of node
};



/*
    Structure of node
 */



struct node
{
    vertex * adjacent;          //variable adjacent of vertex
    node * next;                //pointer for next node
};



/*
    Information of table
*/



class table
{
    public:
   
        table(int size);                           //constructor of journal_entry
        ~table(void);                              //destructor of journal_entry class

    
        int insert_vertex(journal_entry & to_add); //add journal_entry object into vertex
    
        int find_location(char * key_value);       //find location of current vertex
    
        int insert_edge(char * current_vertex, char * to_attach); //add node into list of adjacent
        int checkGraph();                          //wapper check graph
        int checkGraph(node *& head);              //recursion of check graph
        int display_vertex();                      //display vertex
        int display_all(void);                     //display graph

    private:
        vertex * adjacency_list;                   //variable of vertex
        int list_size;                             //size of the array
    
};
