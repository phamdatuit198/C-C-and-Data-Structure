//DAT PHAM
//CS163
//Program 3

/*
 This is a main function of software. the software will call main() function first
 we will create hash table with data is a object of course. Then we will find classes with key is a number of course or name of course.
 */

#include <iostream>
#include "table.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    char numCourse[50];                     //variable is course number
    char nameCourse[300];                   //variable is course name
    char numSection[20];                    //variable is Section Number
    char crn[20];                           //variable is CRN
    char daytime[100];                      //variable is Day and Time of the class
    char description[2000];                 //variable is description of the class
    
    char findnumcourse[50];                 //variable is course number that you need to search
    char findnamecourse[300];               //variable is course name that you need to search
    
    char myChooseType = 'N';                //variable is your choose that you need to add more object  course or it's not
    
    int result = 0;                         //variable is result of the ADT return. It's value zero or one
    int sizeTable;                          //variable is defined size of table, make sure you push prime number
    int size = 10;                          //variable is defined size of array course that you found
    
    course myCourse;                        //object is defined a course that you push
    course* myFoundByNumber;                //myFoundByNumber is a pointer of course
    course* myFoundByName;                  //myFoundByName is a pointer of course
    
    myFoundByNumber = new course[size];
    myFoundByName = new course[size];
    
    cout<<"\nEnter size of table: ";
    cin>>sizeTable;
    
    table  myHashTable(sizeTable);
    cin.ignore(50,'\n');
    //push course into hash table
    do{
        //Enter information of messenge
        
        cout<<"\nEnter number of course: ";
        cin.get(numCourse,50);
        cin.ignore(50,'\n');
        
        cout<<"\nEnter name of course: ";
        cin.get(nameCourse,300);
        cin.ignore(300,'\n');

        cout<<"\nEnter number section of class: ";
        cin.get(numSection,20);
        cin.ignore(20,'\n');

        cout<<"\nEnter CRN of class: ";
        cin.get(crn,20);
        cin.ignore(20,'\n');

        cout<<"\nEnter day time of class: ";
        cin.get(daytime,100);
        cin.ignore(100,'\n');

        cout<<"\nEnter description of class: ";
        cin.get(description,2000);
        cin.ignore(2000,'\n');
        
       
        
        //insert into myCourse object
        
        result = myCourse.insert(numCourse,nameCourse,numSection,crn,daytime,description);
        if(result == 0)
            cout<<"\n insert message is wrong!";
        myCourse.display();
        
        result = myHashTable.insert(nameCourse, myCourse);
        
        //choose add more message or its not
        
        cout<<"\n Do you want to add more: (Y/N) ";
        cin>>myChooseType;
        cin.ignore(100,'\n');

    }while(myChooseType=='Y');
    
    
    
    //display table
    cout<<"\n\n\nDisplay Table\n";
    myHashTable.displayAll();
    
    //----Find course by course number
    
    cout<<"\n\n Find course by course number! \n";
    cout<<"\n Enter number of course you need to find: ";
    cin.get(findnumcourse,50);
    cin.ignore(50,'\n');
    
    //call function retrieve by number
    result = myHashTable.retrieveByNumber(findnumcourse, myFoundByNumber);
    
    //display course is match
    if(result == 1){
     	cout<<"\nshow course we found: \n";
	   for(int i=0;i<size;i++)
            myFoundByNumber[i].display();
    }else
        cout<<"\nNothing can find! \n";
    
    //----Find course by course name
    
    cout<<"\n\n Find course by course name! \n";
    cout<<"\n Enter name of course you need to find: ";
    cin.get(findnamecourse,300);
    cin.ignore(300,'\n');
    
    //call function retrieve by name
    result = myHashTable.retrieveByName(findnamecourse, myFoundByName);
    
    //display course is match
    if(result == 1){
     	cout<<"\nshow course we found: \n";
	   for(int i=0;i<size;i++)
        	    myFoundByName[i].display();
    }else
        cout<<"\nNothing can find! \n";

    return 0;
}











