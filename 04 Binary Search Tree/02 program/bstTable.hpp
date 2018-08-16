//
//  bstTable.hpp
//
//  Dat Pham
//  CS163
//  Program 4
//
//Purpose:
/* This file contains the information about hash table class. this file is some function is defined for hash table class such as insert, retrieve by course number, retrieve by course name and display hash table*/


#include <iostream>
#include "course.hpp"

//*** Structure of table ***

struct n_course{
    course data_course;                 //object course class
    n_course *left;                     //pointer to left another node
    n_course *right;                    //pointer to right another node
};




//*** Infromation of the table class ***

class bstTable{
    
public:
    
    bstTable();                                                 //constructor of table class
    ~bstTable();                                                //destructor of table class
    
    int insert(course & to_add);                                //wapper insert information into table
    int insert(course & to_add, n_course * &root);              //recursion insert information into table
    
    int retrieveByNumber(char _numCourse[], course * & found);                           //wapper find course by course number in table
    int retrieveByNumber(int valueKey, int & index, course * & found, n_course *& root); //recursion find course by course number in table
    

    int retrieveRange(char _from[], char _to[], course * & found);                           //wapper find course by range
    int retrieveRange(int _from, int _to, int & index, course * & found, n_course * & root); //recursion find course by range
    
    int countKey(char *numCourse);                              //return number of course number
    
    int displayAll();                                           //display all course in table
    int destroyTree(n_course *&root);                            //destroy binary search tree by recursion
    
    int inorder(n_course *root);                                //recursion display by inorder sort
    
    int remove(char *_numCourse);                               //wapper remove course number
    int remove(char *_numCourse, n_course *& root);             //recursion remove course number
    
    int removeAll();                                            //remove all of course, this means remove tree

private:
    n_course *root;                                             //pointer root of the bst
   

};
