//DAT PHAM
//CS163
//Program 4

/*
 This is a main function of software. the software will call main() function first
 we will create hash table with data is a object of course. Then we will find classes with key is a number of course or name of course.
 */


#include <iostream>
#include "bstTable.hpp"
using namespace std;

int main(int argc, const char * argv[]) {

    char numCourse[50];                     //variable is course number
    char nameCourse[300];                   //variable is course name
    char numSection[20];                    //variable is Section Number
    char crn[20];                           //variable is CRN
    char daytime[100];                      //variable is Day and Time of the class
    char description[2000];                 //variable is description of the class
    
    char findnumcourse[50];                 //variable is course number that you need to search
    char fromNumCourse[300];                //variable is course name that you need to search
    char toNumCourse[300];                  //variable is course name that you need to search
    char removeNumCourse[50];               //variable is course number that you need to remove
    char myChooseType = 'N';                //variable is your choose that you need to add more object  course or it's not
    char removeAll = 'N';                   //variable is your choose that you need to remove all of course in the bst
    int result = 0;                         //variable is result of the ADT return. It's value zero or one
    int sizeTable;                          //variable is defined size of table, make sure you push prime number
    int size = 100;                          //variable is defined size of array course that you found
    
    course myCourse;                        //object is defined a course that you push
    course* myFoundByNumber;                //myFoundByNumber is a pointer of course
    course* myFoundByRange;                  //myFoundByName is a pointer of course
    
    
    bstTable mybstTable;                    //binary search tree object
    
    myFoundByNumber = new course[size];     //array of course we will found by course number
    myFoundByRange = new course[size];      //array of course we will found by Range
    
    //----Enter information of course
    do{
        
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
            cout<<"\n insert course is wrong!";
        //myCourse.display();
        
         result = mybstTable.insert(myCourse);
        
        //choose add more message or its not
        
        cout<<"\n Do you want to add more: (Y/N) ";
        cin>>myChooseType;
        cin.ignore(100,'\n');
        
    }while(myChooseType=='Y');

    //----Display Binary Search Tree
    
    cout<<"\nDisplay binary search tree: !\n";
    mybstTable.displayAll();
    
    //----Find course by course number
    
    cout<<"\n\n Find course by course number! \n";
    cout<<"\n Enter number of course you need to find: ";
    cin.get(findnumcourse,50);
    cin.ignore(50,'\n');
    
    //call function retrieve by number
    result = mybstTable.retrieveByNumber(findnumcourse, myFoundByNumber);
    
    //display course is match
    if(result == 1)
        for(int i=0;i<size;i++)
            myFoundByNumber[i].display();
    else
        cout<<"\nNothing can find! \n";
    
    
    //----Find course by course range
    
    cout<<"\n\n Find course by course Range! \n";
    cout<<"\n Enter course number from:  ";
    cin.get(fromNumCourse,300);
    cin.ignore(300,'\n');
    
    
    cout<<"\n Enter course number to:  ";
    cin.get(toNumCourse,300);
    cin.ignore(300,'\n');
    //call function retrieve by name
    result = mybstTable.retrieveRange(fromNumCourse, toNumCourse, myFoundByRange) ;
    
    //display course is match
    if(result == 1)
        for(int i=0;i<size;i++)
            myFoundByRange[i].display();
    else
        cout<<"\nNothing can find! \n";
    
    //----Remove course by course number
    
    cout<<"\n Enter course number that you need remove: ";
    cin.get(removeNumCourse,50);
    cin.ignore(50,'\n');
    mybstTable.remove(removeNumCourse);
    
    
    cout<<"\nAfter remove one course of binary search tree: !\n";
    mybstTable.displayAll();
    
    //----Remove binary search tree by course number
    
    cout<<"\n Do you want to remove all of course in the BST: (Y/N) ";
    cin>>removeAll;
    cin.ignore(50,'\n');
    
    if(removeAll == 'Y'){
        result= mybstTable.removeAll();
        
        if(result == 1)
            cout<<"\n Remove done! \n";
        else
            cout<<"\n Can't remove tree! \n";
        
        cout<<"\nDisplay tree after remove binary search tree: !\n";
        result= mybstTable.displayAll();
        
        if(result == 1)
            cout<<"\n Display done \n";
        else
            cout<<"\n Binary Tree is empty! \n";
    }
        
    return 0;
}





