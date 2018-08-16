//
//  journal_entry.cpp
//  graph
//
//  My name: Dat Pham
//  class number: CS163
//  project number: 5
//  Purpose:
/*
        We will implement some function for journal_entry object
*/

#include <iostream>
#include <cstring>
#include "journal_entry.hpp"
using namespace std;


/*
    constructor of journal_entry
*/



journal_entry::journal_entry(){
    title = NULL;
    notes = NULL;
}



/*
    destructor of journal_entry class
*/



journal_entry::~journal_entry(){
    delete[] title;
    delete[] notes;
}



/*
 @purpose: add information into journal_entry object
 
 @param _title
    array character for name of myfriend
 
 @param _notes
    array character for event of myfriend
 
 @return
    0: argument is null
    1: when we add done
 */



int journal_entry::create_entry(char *_title, char *_notes){
    if(!_title || !_notes)
        return 0;
    
    title = new char[strlen(_title)+1];
    strcpy(title, _title);
    
    notes = new char[strlen(_notes)+1];
    strcpy(notes,_notes);
    
    return 1;
}



/*
 @purpose: copy information into journal_entry object
 
 @param a_new_entry
     is a object of journal_entry class
 
 @return 
    0: argument is NULL
    1: when we add done
 */



int journal_entry::copy_entry(journal_entry &a_new_entry){
    
    //check argument is Null or it's not
    
    if(isEmpty(a_new_entry)==0)
        return 0;
    
    title = new char[strlen(a_new_entry.title)+1];
    strcpy(title,a_new_entry.title);
    
    notes = new char[strlen(a_new_entry.notes)+1];
    strcpy(notes, a_new_entry.notes);
    
    return 1;

}



/*
 @purpose: check object is NULL or it isn't
 
 @param check_entry
    is a object of journal_entry class
 
 @return
    0: argument is NULL
    1: when we add done
 */




int journal_entry::isEmpty(journal_entry &check_entry){

    if(check_entry.title==NULL || check_entry.notes == NULL)
        return 0;
    else
        return 1;
}




/*
 @purpose: compare two vertex
 
 @param is_it_a_match
    title of vertex
 
 @return 1
    if two vertex is same
 @return 0
    if two vertex is different
 */



bool journal_entry::compare(char * is_it_a_match){
    
    if(strcmp(title, is_it_a_match)==0)
        return true;
    
    return false;
}




/*
 @purpose: get title of current vertex
 
 @return title
    when we add done
 */



char* journal_entry::getTitle(){
    return title;
}



/*
 @purpose: get notes of current vertex
 
 @return notes
    when we add done
 */



char* journal_entry::getNotes(){
    return notes;
}



/*
 @purpose: display data member
 
 @return 1
    when we add done
 */

int journal_entry::display(){

    cout<<"\n"<<title<<":"<<notes<<"\n";
    return 1;
}







