//
//  course.hpp
//
//  DAT PHAM
//  CS163
//  Program 3
//
//Purpose:
/* This file contains the information about course class. this file is some function is defined for couse class*/

#include <iostream>


// Information of course class

class course{

    public:
    
        course();                                //constructor of course class
        ~course();                               //destructor of course class
        int insert(char _numCourse[], char _nameCourse[], char _numSection[], char _crn[], char _daytime[], char _description[]);                         //insert information into course

        int copy(course &_copyFrom);            //copy information from argument into data member
        int isEmpty();                          //check object is empty or it's not
        int checkNumber(char _numCourse[]);     //check course number of argument is match with data member or it's not
        int checkName(char _nameCourse[]);      //check course name of argument is match with data member or it's not
        int display();                          //display information of object course
    
    private:
        char *numCourse;                        //course number
        char *nameCourse;                       //course name
        char *numSection;                       //Section number
        char *crn;                              //CRN of class
        char *daytime;                          //Day and time of the class
        char *description;                      //Description of the class
    
};

