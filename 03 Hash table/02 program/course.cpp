//course.cpp
//DAT PHAM
//CS163
//Program 3
//
//Purpose:
/*
 Purpose: we are using ADT for managing operation of course
 This is a function of course class such as insert, copy, isempty and display. Opearation of the course in here.
 */


#include "course.hpp"
#include  <cstring>

using namespace::std;


/*
    Constructor of course
 */


course::course(){
    numCourse = NULL;
    nameCourse = NULL;
    numSection = NULL;
    crn = NULL;
    daytime = NULL;
    description = NULL;
}


/*
    Destructor of course
 */

course::~course(){
    
    if(numCourse)
        delete [] numCourse;
    
    if(nameCourse)
        delete [] nameCourse;
    
    if(numSection)
        delete [] numSection;
    
    if(crn)
        delete [] crn;
    
    if(daytime)
        delete [] daytime;
    
    if(description)
        delete [] description;
    
}

/*
 
 @purpose: add information for course
 
 @param _numCourse[]
    Array character of number course
 
 @param _nameCourse[]
    Array character of name course
 
 @param _numSection[]
    Array character of number section
 
 @param _crn[]
    Array character of crn of class
 
 @param _daytime[]
    Array character of daytime of class
 
 @param _description[]
    Array character of description of class
 
 @return:
    0 when argument is NULL
    1 when we insert done
 
 */

int course::insert(char _numCourse[], char _nameCourse[], char _numSection[], char _crn[], char _daytime[], char _description[]){
    
    //check argument has NULL or they aren't
    
    if( _numCourse==NULL || _nameCourse == NULL ||  _numSection == NULL ||  _crn == NULL ||  _daytime == NULL ||  _description == NULL)
            return 0;
    else{
        //copy argument into the data member
        
        //create a variable and deep copy
        
        if(numCourse)
            delete [] numCourse;
        
        numCourse = new char[strlen(_numCourse)+1];
        strcpy(numCourse, _numCourse);
        
        if(nameCourse)
            delete [] nameCourse;
        
        nameCourse = new char[strlen(_nameCourse)+1];
        strcpy(nameCourse, _nameCourse);
        
        if(numSection)
            delete [] numSection;
        
        numSection = new char[strlen(_numSection)+1];
        strcpy(numSection, _numSection);
        
        if(crn)
            delete [] crn;
        
        crn = new char[strlen(_crn)+1];
        strcpy(crn, _crn);
        
        if(daytime)
            delete [] daytime;
        
        daytime = new char[strlen(_daytime)+1];
        strcpy(daytime, _daytime);
        
        if(description)
            delete [] description;
        
        description = new char[strlen(_description)+1];
        strcpy(description, _description);
        
        
        return 1;
    }
}



/*
 
 @purpose: copy from object course to another object course
 
 @param _copyFrom
    object course class
 @return:
    0: if _copyFrom is NULL
    1: when we insert done
 
 */


int course::copy(course & _copyFrom){
    
    //check argument has NULL or no
    
    if(_copyFrom.isEmpty()==0)
        return 0;
    else{
        insert(_copyFrom.numCourse,_copyFrom.nameCourse,_copyFrom.numSection,_copyFrom.crn,_copyFrom.daytime,_copyFrom.description);
        return 1;
    }
}



/*
 
 @purpose: check course is NULL of it is not
 
 @return
    0: if data member is NULL
    1: when we are be done
 */


int course::isEmpty(){
    
    //check data member of argument has NULL or no
    
    if( numCourse == NULL || nameCourse == NULL ||  numSection == NULL ||  crn == NULL ||  daytime == NULL ||  description == NULL)
        return 0;
    else
        return 1;
    
}




/*
 
 @purpose: check course number of argument is match with data member or it's not
 @param _numCourse[]
    Array of character course number
 @return
    0: if data of argument is NULL
    1: when we are be done
 */


int course::checkNumber(char _numCourse[]){
    
    //check data of argument has NULL or no
    
    if(_numCourse == NULL)
        return 0;
    
    if (strcmp(numCourse, _numCourse) == 0)
        return 1;
    else
        return 0;
}



/*
 
 @purpose: check course name of argument is match with data member or it's not
 @param _nameCourse[]
    Array of character course number
 @return
    0: if data of argument is NULL
    1: when we are be done
 */


int course::checkName(char _nameCourse[]){
    
    //check data of argument has NULL or no
    
    if(_nameCourse == NULL)
        return 0;
    
    if (strcmp(nameCourse, _nameCourse) == 0)
        return 1;
    else
        return 0;
}


/*
 
 @purpose: display information for course
 
 @return
    0: if data member is NULL
    1: when we are be done
 */


int course::display(){
    
    //check data member is Null or it's not
    
    int result = isEmpty();
    if(result == 0 )
        return 0;
    else{

        cout<<"\n";
        cout<<"\n Number of course: "<<numCourse;
        cout<<"\n Name of course: "<<nameCourse;
        cout<<"\n Number of Section: "<<numSection;
        cout<<"\n CRN of class: "<<crn;
        cout<<"\n Daytime of class: "<<daytime;
        cout<<"\n Description: "<<description;
        return 1;
    }
}











