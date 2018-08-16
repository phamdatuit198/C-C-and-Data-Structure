/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.a
 ** Date: May 22, 2017
 ** Description: Write a template class called ValSet, which represent a mathematical set of value
 
 ***************************************************************************/


#ifndef VALSET_HPP
#define VALSET_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

template <class T>
class ValSet{
    
private:
    T * aptr;                      //a pointer to T that points to a dynamically allocated array
    int sizeArray;                 //size of Array
    int value;                     //stores the number of value array
public:
    ValSet();                      //default constructor function
    ValSet(int);                   //constructor function with parameter
    ValSet(const ValSet &);        //Copy constructor function
    ~ValSet();                     //Destructor function
    
    int size() const;              //function return number of value of array
    bool isEmpty();                //function check value is zero or it is not
    bool contains(T);              //function check parameter in array
    void add(T);                   //function add new element to array
    void remove(T);                //function remove element from array
    
    vector<T> getAsVector();       //show element of array
    T &operator[] (int);           //overload assignment operator
    ValSet &operator = (ValSet);   //overload assignment operator
    
};

#endif
