//
//  table.hpp
//
//  DAT PHAM
//  CS163
//  Program 3
//
//Purpose:
/* This file contains the information about hash table class. this file is some function is defined for hash table class such as insert, retrieve by course number, retrieve by course name and display hash table*/

#include <iostream>
#include "course.hpp"


//*** Structure of table ***

struct n_course{
    course data_course;                 //object course class
    n_course *next;                     //pointer to next another node
};




//*** Infromation of the table class ***

class table{
    
    public:
    
        table(int size);                 //constructor of table class
        ~table();                        //destructor of table class
        int insert(char  _keyvalue[], course & to_add);    //insert information into table
        int retrieveByNumber(char  _numCourse[], course * & found); //find course by course number in table
        int retrieveByName(char _nameCourse[],course * & found);    //find course by course name in table
        int displayAll();                   //display all course in table
    
    private:
    
        n_course **hash_table;              //hash_table is a pointer to pointer to n_course
        int hash_table_size;                //size of array table
        int hashfunction(char *key);        //function is choose location for pushing new course into table
};



